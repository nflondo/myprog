import sys
import pygame
from controller import Controller

def run_game():
	#Initialize and create screen project
	pygame.init()
	screen = pygame.display.set_mode((1200,800))
	pygame.display.set_caption("Blue background")
	
	# set bg color
	bg_color = (0, 0, 255)
	
	# make a ship
	controller = Controller(screen)
	
	# Main loop
	while True:
		
		# What for keyboard and mouse events
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				sys.exit()
				
		# Redraw the screen during each pass through the loop
		screen.fill(bg_color)
		controller.blitme()
				
		# Make the most of recently drawn screen visible
		pygame.display.flip()
		
run_game()
