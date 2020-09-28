import pyglet

class Cell:
    def __init__(self, squares_size: int, posx: int, posy: int, image: str = 'res/sprites/cell.png', **kwargs) -> None:
        image = pyglet.image.load(image)
        self.sprite = pyglet.sprite.Sprite(image, x=posx * squares_size, y=posy * squares_size, **kwargs)

    def draw(self) -> None:
        self.sprite.draw()
