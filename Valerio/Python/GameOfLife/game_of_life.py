import pyglet
from AppKit import NSScreen
from pyglet.gl import *

HEIGHT = int(NSScreen.mainScreen().frame().size.height)
WIDTH = int(NSScreen.mainScreen().frame().size.width)

matrix = [[0 for i in range(HEIGHT // 10)] for j in range(WIDTH // 10)]

def fits(x, y):
    l = len(matrix), len(matrix[0])
    return x >= 0 and y >= 0 and x < l[1] and y < l[0]

def neighborhood(x, y):
    n = x, y - 1
    ne = x + 1, y - 1
    e = x + 1, y
    se = x + 1, y + 1
    s = x, y + 1
    sw = x - 1, y + 1
    w = x, y - 1
    nw = x - 1, y - 1
    rose = n, ne, e, se, s, sw, w, nw
    res = []
    for d in rose:
        if fits(*d):
            res.append(matrix[d[1]][d[0]])
    return res

def alives(neighbors):
    count = 0
    for neighbor in neighbors:
        if neighbor:
            count += 1
    return count


def life():
    row, column = len(matrix), len(matrix[0])
    to_change = []
    for i in range(row):
        for j in range(column):
            nb = neighborhood(j,i)
            alives_in_neighborhood = alives(nb)
            if (alives_in_neighborhood < 2 or alives_in_neighborhood > 3) and matrix[i][j]:
                to_change.append((i, j, 0))
                print(nb)
            elif alives_in_neighborhood == 3 and not matrix[i][j]:
                to_change.append((i, j, 1))
                print(nb)

    for i, j, n in to_change:
        matrix[i][j] = n


#matrix[y][x]
matrix[55][80] = 1
matrix[55][82] = 1
matrix[56][82] = 1
matrix[57][84] = 1
matrix[58][84] = 1
matrix[59][84] = 1
matrix[58][86] = 1
matrix[59][86] = 1
matrix[60][86] = 1
matrix[59][87] = 1






win = pyglet.window.Window(WIDTH, HEIGHT - 80)
glClear(GL_COLOR_BUFFER_BIT)

@win.event
def on_draw():
    glBegin(GL_POINTS)
    for row in range(len(matrix)):
        for column in range(len(matrix[row])):
            if matrix[row][column]:
                for i in range(10):
                    for j in range(10):
                        glVertex2f(column * 10 + i, row * 10 + j)

    glEnd()

@win.event
def on_resize(weight, height):
    glViewport(0,0, weight, height)

count = 0
while True:
    life()
    count += 1
    print(f'\x1b[31m{count}\x1b[0m')
    if count == 40:
        break

pyglet.app.run()
