import math
import turtle


def spiral(angle):
    t = turtle.Turtle()
    a = 0
    while (True):
        a += (1 - 5 ** (1 / 2)) / 2 ** ((math.log2(90 / angle)) + 1)
        t.fd(a)
        t.lt(angle)


a = float(input("Che angolo? "))

spiral(a)
