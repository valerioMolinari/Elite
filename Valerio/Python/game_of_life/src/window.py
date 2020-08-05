import pyglet
from src.world import *
from src.cell import Cell

class Window(pyglet.window.Window):
    def __init__(self, width, height, squares_size: int, configuration: tuple = None, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.world = World(width, height, squares_size, configuration)

    def on_draw(self):
        self.clear()
        self.world.draw()

    def update(self, _):
        self.world.draw(self.world.update)
