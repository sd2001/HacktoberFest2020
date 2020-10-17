#!/usr/bin/python3

import turtle

#defining colors

colors = ['red' , 'yellow', 'green', 'purple', 'blue', 'orange', 'pink']

#setup turtle pen

t = turtle.Pen()

#change the speed of the turtle 

t.speed(12)

#changes the background color

turtle.bgcolor('white')

#make the spiral web

for x in range(900):
    t.pencolor(colors[x%6]) #setting color
    t.width(x/100 + 1) #setting width
    t.forward(x) #moving forward
    t.left(59) # moving left
turtle.done()
