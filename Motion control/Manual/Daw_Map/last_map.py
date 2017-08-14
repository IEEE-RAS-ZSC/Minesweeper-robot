# -*- coding: utf-8 -*-
"""
Created on Mon Apr 10 18:39:52 2017

@author: mohammad
"""
Range = 40
import pygame

# Define some colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
RED   = (255, 0, 0)
 
# This sets the WIDTH and HEIGHT of each grid location
WIDTH  = 12
HEIGHT = 12
 
# This sets the margin between each cell
MARGIN = 5
 
# --- Create grid of numbers
grid = [[0 for x in range(Range)] for y in range(Range)]
#grid[1][5] = 1  # Set row 1, column 5 to one

# Initialize pygame
pygame.init()
 
# Set the HEIGHT and WIDTH of the screen
WINDOW_SIZE = [int(WIDTH*Range*1.48),int(HEIGHT*Range*1.48)]
screen = pygame.display.set_mode(WINDOW_SIZE)
 
# Set title of screen
pygame.display.set_caption("Array Backed Grid")
 
# Loop until the user clicks the close button.
done = False
 
# Used to manage how fast the screen updates
clock = pygame.time.Clock()
 
# -------- Main Program Loop -----------
while not done:
    for event in pygame.event.get():  # User did something
        if event.type == pygame.QUIT:  # If user clicked close
            done = True  # Flag that we are done so we exit this loop
        else:
            with open("new.txt", "r") as myFile:
                for line in myFile:
                    column, row, sqcolor = line.strip().split()
		    row = int(row)
		    column = int(column)
		    grid[row][column] = sqcolor
                    print(column, row, sqcolor)
		
            #print("Click ", pos, "Grid coordinates: ", row, column)
 
    # Set the screen background
    screen.fill(WHITE)

    # Draw the grid
    for row in range(Range):
        for column in range(Range):
            #color = WHITE
            if grid[row][column] == "b":
                color = BLACK
                pygame.draw.rect(screen,
                             color,
                             [(MARGIN + WIDTH) * column + MARGIN,
                              (MARGIN + HEIGHT) * row + MARGIN,
                              WIDTH,
                              HEIGHT])
            elif grid[row][column] == "s":
                color = RED
                pygame.draw.rect(screen,
                             color,
                             [(MARGIN + WIDTH) * column + MARGIN,
                              (MARGIN + HEIGHT) * row + MARGIN,
                              WIDTH,
                              HEIGHT])
            else :
                color = GREEN
                pygame.draw.rect(screen,
                             color,
                             [(MARGIN + WIDTH) * column + MARGIN,
                              (MARGIN + HEIGHT) * row + MARGIN,
                              WIDTH,
                              HEIGHT])
    # Limit to 60 frames per second
    clock.tick(60)
 
    # Go ahead and update the screen with what we've drawn.
    pygame.display.flip()
 
# Be IDLE friendly. If you forget this line, the program will 'hang'
# on exit.
pygame.quit()
