import math
import time
import turtle

class Vector:
    x = 0.0
    y = 0.0

    def __mul__(self, a: float):
        v = Vector()
        v.x = self.x * a
        v.y = self.y * a
        return v

    def __add__(self, a: Vector):
        v = Vector()
        v.x = self.x + a.x
        v.y = self.y + a.y
        return v

    def __sub__(self, a: Vector):
        v = Vector()
        v.x = self.x - a.x
        v.y = self.y - a.y
        return v

    def __abs__(self):
        return math.sqrt(self.x**2 + self.y**2)

class Body:
    def __init__(self):
        self.pos = Vector()
        self.vel = Vector()
        self.m = 20.0
        self.r = 30.0
        self.k = 20.0

    def upr(self, b: Body):
        d = b.pos - self.pos
        md = abs(d)
        d_dir = d * (1 / md)
        sr = self.r + b.r
        if md < sr:
            dx = sr - md
            return d_dir * (dx * self.k)
        return Vector()



    def affect(self, fs : list[Vector], dt: float):
        r = Vector()
        for f in fs:
            r = r + f
        a = r * (1.0 / self.m)
        du = a * dt
        self.vel = self.vel + du

    def move(self, dt: float):
        self.pos = self.pos + (self.vel * dt)

bs = [Body(), Body(), Body(), Body()]
bs[1].pos.x = 100
bs[1].vel.x = 40
bs[2].pos.x = 200
# bs[2].m = 20
bs[3].pos.x = 20
bs[3].pos.y = 200
bs[3].vel.x = 20
bs[3].vel.y = -40

screen = turtle.Screen()
t = turtle.Turtle()
t.speed(0)
t.hideturtle()
t.penup()
t.color("black", "red")

def circle(x, y, r):
    t.goto(x, y - r)
    with t.fill():
        t.circle(r)


freq = 30
T = 1 / freq

screen.delay(0)
def render():
    t.clear()
    for b1 in bs:
        fs = []
        for b2 in bs:
            if b1 != b2:
                fs.append(b2.upr(b1))
        b1.affect(fs, T)

    for b1 in bs:
        b1.move(T)

    for b1 in bs:
        circle(b1.pos.x, b1.pos.y, b1.r)

    screen.ontimer(render, int(T * 1000))

render()
screen.mainloop()