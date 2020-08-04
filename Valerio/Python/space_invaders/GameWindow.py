import pyglet
from GameObject import GameObject
from pyglet.window import key

class GameWindow(pyglet.window.Window):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.set_location(400, 100)
        self.frame_rate = 1/60
        self.player = GameObject(500, 200, "PlayerShip.png")

    def on_key_press(self, symbol, modifiers):
        if symbol == key.RIGHT:
            self.player.velx = 300
        elif symbol == key.LEFT:
            self.player.velx = -300

    def on_key_release(self, symbol, modifiers):
        if symbol in (key.RIGHT, key.LEFT):
            self.player.velx = 0

    def on_draw(self):
        self.clear()
        self.player.draw()

    def update(self, dt):
        self.player.update(dt)


if __name__ == "__main__":
    window = GameWindow(1200, 900, "Space Invaders")
    pyglet.clock.schedule_interval(window.update, window.frame_rate)
    pyglet.app.run()
