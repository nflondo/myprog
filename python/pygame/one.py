#!/usr/bin/python
# 
import pygame, sys
from pygame.locals import *

def main():
    pygame.init()
    screen = pygame.display.set_mode((400,400)) 
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                sys.exit()
    
if __name__=='__main__':
    main()
