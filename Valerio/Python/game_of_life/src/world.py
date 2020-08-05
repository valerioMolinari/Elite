from src.cell import Cell
from AppKit import NSScreen
from random import randint
from threading import Thread
import numpy as np
from os import system
import json
import pyglet
import math

class World:
    def __init__(self, width, height, squares_size: int, configuration: tuple = None) -> None:
        self.WIDTH = width
        self.HEIGHT = height
        self.squares_size = squares_size
        self.matrix = np.zeros((self.WIDTH // squares_size, self.HEIGHT // squares_size), dtype=np.uint8)
        self.shape = self.matrix.shape
        self.population = configuration
        if configuration is not None:
            for row, column in configuration:
                self.__give_birth(row, column)
        else:
            self.population = self.__populate()

    def __give_birth(self, row: int, col: int) -> None:
        self.matrix[row, col] = 1

    def __kill(self, row: int, col: int) -> None:
        self.matrix[row, col] = 0

    def __fits(self, row: int, col: int) -> bool:
        return row >= 0 and col >= 0 and row < self.shape[0] and col < self.shape[1]

    def __get_neighborhood(self, row: int, col: int) -> list:
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
        neighbors = []
        for direction in directions:
            if self.__fits(*directions[direction]):
                d = directions[direction]
                neighbors.append(self.matrix[d[0], d[1]])
        return neighbors

    def __count_nonzero(self, neighbors: list) -> int:
        count = 0
        for neighbor in neighbors:
            if neighbor and count < 4:
                count += 1
        return count

    def __populate(self) -> None:
        population = []
        for row in range(self.shape[0]):
            system("clear")
            print(f"populating: {round(row * 100 / self.shape[0], 2)}%")
            for col in range(self.shape[1]):
                r = randint(0,1)
                if r:
                    self.__give_birth(row, col)
                    population.append((row, col))
        return population

    def update(self) -> int:
        to_change = []
        for row in range(self.shape[0]):
            for col in range(self.shape[1]):
                neighborhood = self.__get_neighborhood(row, col)
                non_zero = self.__count_nonzero(neighborhood)
                if non_zero < 2 or non_zero > 3:
                    to_change.append((row, col, 0))
                elif non_zero == 3:
                    to_change.append((row, col, 1))
        self.population = []
        for row, col, status in to_change:
            if status:
                self.__give_birth(row, col)
                self.population.append((row, col))
            else:
                self.__kill(row, col)


    def draw(self, callback=lambda:None) -> None:
        callback()
        count = 0
        l = len(self.population)
        batch = pyglet.graphics.Batch()
        cent = l // 100
        cells = []
        for row, col in self.population:
            if not cent:
                system("clear")
                print("populating: 100.0%")
                print("drawing   : 100.0%")
            elif not count % cent:
                system("clear")
                print("populating: 100.0%")
                print(f"drawing   : {round(count * 100 / l, 2)}%")
            count += 1
            cells.append(Cell(self.squares_size, row, col, batch=batch).sprite)
        batch.draw()

class Drawer(Thread):
    def __init__(self, start, end, squares_size, batch, batch_list):
        Thread.__init__(self)
        self.start = start
        self.end = end
        self.squares_size = squares_size
        self.batch = batch
        self.batch_list = batch_list

    @staticmethod
    def needed(x, y):
        def is_int(n):
            #print(n - int(n))
            return not (n - int(n))
        def nearest(x, y, z):
            return y if x - z > z - y else x
        size = x * y
        z = math.sqrt(size)
        if is_int(z):
            return z
        else:
            z = int(z)
            up = down = z
            while not (is_int(size / up) or is_int(size / down)):
                up   += 1
                down -= 1
            return nearest(up, down, z)
