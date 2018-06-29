# alien_invasion
#import sys
import pygame


from settings import Settings
from ship import Ship
import game_functions as gf

def run_game():
	# Initialize game and create a screen object.
	pygame.init()
	# Creates an instance of settings
	ai_settings = Settings()
#	screen = pygame.display.set_mode((1200, 800))
	screen = pygame.display.set_mode(
		(ai_settings.screen_width, ai_settings.screen_height))
	pygame.display.set_caption("Alien Invasion by Nef")
	
	# Make a ship
	ship = Ship(screen)	
	
	# Start the main loop for the game.
	while True:
		gf.check_events(ship)
		ship.update()
		gf.update_screen(ai_settings, screen, ship)		

		
run_game()
