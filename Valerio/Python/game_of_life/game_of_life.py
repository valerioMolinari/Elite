import pyglet
from AppKit import NSScreen
import numpy as np
from random import randint

def give_birth(row, col):
    matrix[row, col] = 1

def kill(row, col):
    matrix[row, col] = 0

def fits(row, col):
    shape = matrix.shape
    return row >= 0 and col >= 0 and row < shape[0] and col < shape[1]

def get_neighboorhood(row, col):
    directions = {
        'nw': (row - 1, col - 1),
        'n' : (row - 1, col),
        'ne': (row - 1, col + 1),
        'e' : (row, col + 1),
        'se': (row + 1, col + 1),
        's' : (row + 1, col),
        'sw': (row + 1, col - 1),
        'w' : (row, col - 1)
    }
    neighboors = []
    for direction in directions:
        if fits(*directions[direction]):
            d = directions[direction]
            neighboors.append(matrix[d[0], d[1]])
    return np.array(neighboors)

def live():
    to_change = []
    for row in range(shape[0]):
        for col in range(shape[1]):
            non_zero = np.count_nonzero(get_neighboorhood(row, col))
            if non_zero < 2 or non_zero > 3:
                to_change.append((row, col, 0))
            elif non_zero == 3:
                to_change.append((row, col, 1))
    for row, col, status in to_change:
        give_birth(row, col) if status else kill(row, col)
    print(matrix)

def populate():
    for row in range(shape[0]):
        for col in range(shape[1]):
            r = randint(0,1)
            give_birth(row, col) if r else kill(row, col)


#dimensioni dello schermo e dei quadratini per pyglet
WIDTH = int(NSScreen.mainScreen().frame().size.width)
HEIGHT = int(NSScreen.mainScreen().frame().size.height)
SQUARES_SIZE = 10

matrix = np.zeros((WIDTH // SQUARES_SIZE, HEIGHT // SQUARES_SIZE), dtype=np.uint8)
shape = matrix.shape
#matrix[y][x]
#matrix[len(Y) - y][x]

def main():
    populate()
    while True:
        live()



if __name__ == '__main__':
    main()
