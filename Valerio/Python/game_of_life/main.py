from src.window import Window
from AppKit import NSScreen
import pyglet

WIDTH = int(NSScreen.mainScreen().frame().size.width)
HEIGHT = int(NSScreen.mainScreen().frame().size.height) - 100
SQUARES_SIZE = 10

window = Window(SQUARES_SIZE, None, WIDTH, HEIGHT, "Game of Life")
pyglet.clock.schedule_interval(window.update, 2)
pyglet.app.run()
