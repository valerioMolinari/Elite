from src.window import Window
from AppKit import NSScreen
import pyglet

WIDTH = int(NSScreen.mainScreen().frame().size.width)
HEIGHT = int(NSScreen.mainScreen().frame().size.height) - 100
SQUARES_SIZE = 10

config = [
    (100, 50), (100, 49), (100, 46), (101, 50), (101, 53), (102, 50), (102, 53),
    (102, 54), (103, 52), (104, 52), (104, 53), (104, 54)
]


window = Window(WIDTH, HEIGHT, SQUARES_SIZE, None, WIDTH, HEIGHT, "Game of Life")
pyglet.clock.schedule_interval(window.update, 4)
pyglet.app.run()
