#!/usr/bin/env python2.7
import rospy
from std_msgs.msg import Char, UInt16MultiArray
import pygame

# Playground area
Range = 20
# Colors  code
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
RED   = (255, 0, 0)

# Block area
WIDTH  = 30
HEIGHT = 30

# Space between the blocks
MARGIN = 5

# Draw playground
grid = [[0 for x in range(Range)] for y in range(Range)]

# Initializing ROS and Pygame
rospy.init_node('Map', anonymous=True)
pygame.init()

# Edit the window size to fit all blocks
WINDOW_SIZE = [int(WIDTH*Range*1.2),int(HEIGHT*Range*1.18)]
screen = pygame.display.set_mode(WINDOW_SIZE)

# Change the name of the window
pygame.display.set_caption("Mine Location")

# Start the clock for update 
clock = pygame.time.Clock()


# Create a class for updating the map
class mine(object) :
	row=0
	column=0
	square_color=" "
		
mine = mine()
	
	
def update(data):
        if data.data == 98:
                mine.square_color = "b"
        elif data.data == 115:
                mine.square_color = "s"
        else:
                mine.square_color = "n"

def coordnat(data):
        #rospy.loginfo(data.data)             
        mine.row = data.data[1]
        mine.column = data.data[2]

def mainloop() :
        rospy.Subscriber("Mine_located", Char, update)
        rospy.Subscriber("Mine_place", UInt16MultiArray, coordnat)
        done = False
        while not done:
                #update()
                for event in pygame.event.get():
                        if event.type == pygame.QUIT:
                                done = True
                grid[mine.row-1][mine.column-1] = mine.square_color
                #rospy.loginfo(mine.square_color)
                screen.fill(WHITE)
                for row in range(Range):
                        for column in range(Range):
                                if grid[row][column] == "b":
                                        #rospy.loginfo("b")
                                        color = BLACK
                                        pygame.draw.rect(screen, color,
                                                         [(MARGIN + WIDTH) * column + MARGIN,
                                                          (MARGIN + HEIGHT) * row + MARGIN,WIDTH,HEIGHT])
                                elif grid[row][column] == "s":
                                        #rospy.loginfo("s")
                                        color = RED
                                        pygame.draw.rect(screen, color,
                                                         [(MARGIN + WIDTH) * column + MARGIN,
                                                          (MARGIN + HEIGHT) * row + MARGIN,WIDTH,HEIGHT])
                                else :
                                        color = GREEN
                                        #rospy.loginfo("g")
                                        pygame.draw.rect(screen, color,
                                                         [(MARGIN + WIDTH) * column + MARGIN,
                                                          (MARGIN + HEIGHT) * row + MARGIN,WIDTH,HEIGHT])
	
		clock.tick(6)
		#rospy.spin()

		pygame.display.flip()
	pygame.quit()
	
mainloop()




	
