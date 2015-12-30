#!/usr/bin/python
# 
import pygame, sys
from pygame.locals import *
RED = (255, 0,0)
BLACK = (0,0,0)

def main():
    pygame.init()
    # The size 400x400 is in pixels
    screen = pygame.display.set_mode((900,300))
    x = 20
    y = 20 
    # This paints the background of the square box black
    screen.fill(BLACK)
    # Circle is created 20 from left and 20 from top of screen. 10 is radius.
    pygame.draw.circle(screen, RED, (x,y),10)
    pygame.display.update()
    
    # This checks for quit events (#12 I think) when clicking on X
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                sys.exit()
        
        x +=1
        # This line repaints the background on the square black
        pygame.draw.rect(screen,BLACK, (0,0,900,300))
        pygame.draw.circle(screen, RED, (x,y),10)
        pygame.display.update()
        
if __name__=='__main__':
    main()
