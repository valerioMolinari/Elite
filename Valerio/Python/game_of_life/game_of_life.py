import pyglet
from AppKit import NSScreen
import numpy as np

def give_birth(row, col):
    matrix[row, col] = 1

def kill(row, col):
    matrix[row, col] = 0

def get_neighboorhood(row, col):
    pass

WIDTH = int(NSScreen.mainScreen().frame().size.width)
HEIGHT = int(NSScreen.mainScreen().frame().size.height)
SQUARES_SIZE = 10
WIDTH, HEIGHT

WIDTH, HEIGHT

matrix = np.zeros((WIDTH // SQUARES_SIZE, HEIGHT // SQUARES_SIZE), dtype=np.uint8)
