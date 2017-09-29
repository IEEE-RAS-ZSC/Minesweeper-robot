
Range = 40
import pygame

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
RED   = (255, 0, 0)

WIDTH  = 12
HEIGHT = 12
 
MARGIN = 5
 
grid = [[0 for x in range(Range)] for y in range(Range)]

pygame.init()
 
WINDOW_SIZE = [int(WIDTH*Range*1.48),int(HEIGHT*Range*1.48)]
screen = pygame.display.set_mode(WINDOW_SIZE)
 
pygame.display.set_caption("Array Backed Grid")
 
clock = pygame.time.Clock()

class mine(object) :
	r=0
	c=0
	sq="s"
		
mine = mine()	
def mainloop() :
	
	done = False
	while not done:	
		update()
		for event in pygame.event.get():  
			if event.type == pygame.QUIT:  
				done = True  
		grid[mine.r-1][mine.c-1] = mine.sq

		screen.fill(WHITE)
		for row in range(Range):
			for column in range(Range):
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
	
	
		clock.tick(6)

		pygame.display.flip()
	pygame.quit()
	
	
	
def update():
	while mine.r < Range:
		rw = mine.r
		mine.r=mine.r+1
		mine.c=mine.c+1
		mine.sq="s"
		break
	
		
	
			
			
			
			
			
mainloop()




	
