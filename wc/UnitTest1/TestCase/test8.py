import turtle
N=eval(input())
turtle.setup(650,350,200,200)
r=5
for i in range (N):
    turtle.circle(r)
    turtle.color("green")
    r+=5
