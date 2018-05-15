from turtle import *
setup(700, 800, 100, 100)
pensize(10)
penup()
fd(-100)
pendown()

fillcolor("violet")
speed(1000)
begin_fill()
color("5,4,4")
ang=-60
seth(ang)
for i in range(6):
    circle(100, 120)
    ang+=60
    seth(ang)
end_fill()

