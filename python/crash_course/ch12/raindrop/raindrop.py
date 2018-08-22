# raindrop
import pygame
from raindrop_settings import Settings
from pygame.sprite import Group
import raindrop_functions as rf

def run_game():
	# Initialize game and create a screen object.
	pygame.init()	
	game_settings = Settings()
#	screen = pygame.display.set_mode((1200, 800))
	screen = pygame.display.set_mode(
		(game_settings.screen_width, game_settings.screen_height))
	pygame.display.set_caption("Raindrop by Nef")
	# Make raindrop
	drops = Group()
	
	# Create the fleet of raindrops
	rf.create_fleet(game_settings, screen, drops)
	
run_game()
