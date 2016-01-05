#!/usr/bin/python
# Drawing Text

import pygame, sys
from pygame.locals import *

def main():
    pygame.init()
    
    screen = pygame.display.set_mode((400,300))
    
    screen.fill((0, 0, 0))
    pygame.display.update()
    
    fonts = pygame.font.get_fonts()
    font = fonts.pop()
    
    while fonts:
        try:
            new_font = pygame.font.SysFont(font, 30)
        except:
            pass
            
        text = new_font.render(font, 1, (255,255,255))
        
        screen.fill((0,0,0))
        screen.blit(text, (40, 40))
        pygame.display.update()
        for event in pygame.event.get():
            if event.type == KEYDOWN:
                font = fonts.pop()
                
if __name__=='__main__':
    main()           
