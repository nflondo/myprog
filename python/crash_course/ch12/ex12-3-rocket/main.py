import sys
import pygame
from controller import Controller
from settings import Settings

def run_game():
	#Initialize and create screen project
	pygame.init()
	game_settings = Settings()
#	screen = pygame.display.set_mode((1200,800))
	screen = pygame.display.set_mode(
		(game_settings.screen_width, game_settings.screen_height))
	pygame.display.set_caption("Rocket game")
	
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
