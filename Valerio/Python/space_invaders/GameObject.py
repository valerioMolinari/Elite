import pyglet


class GameObject:
    def __init__(self, posx, posy, image=None):
        self.posx = posx
        self.posy = posy
        self.velx = 0
        self.vely = 0
        if image:
            image = pyglet.image.load('res/sprites/' + image)
            self.sprite = pyglet.sprite.Sprite(image, x=posx, y=posy)



    def draw(self):
        self.sprite.draw()

    def update(self, dt):
        self.sprite.x += self.velx * dt
        self.sprite.y += self.vely * dt
