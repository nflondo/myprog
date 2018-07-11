import pygame

from settings import Settings
from rocket import Rocket
import functions as fn


def run_game():
	#Initialize and create screen project
	pygame.init()
	game_settings = Settings()
#	screen = pygame.display.set_mode((1200,800))
	screen = pygame.display.set_mode(
		(game_settings.screen_width, game_settings.screen_height))
	pygame.display.set_caption("Rocket game")
	
	# make a rocket
	rocket = Rocket(game_settings, screen)
	
	# Main loop
	while True:
		# Watch for keyboard and mouse events
		fn.check_events(rocket)
		rocket.update()
		fn.update_screen(game_settings, screen, rocket)
		
run_game()
