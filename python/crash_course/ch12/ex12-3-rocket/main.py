import pygame
from pygame.sprite import Group
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
	# Make a group to store bullets in.
	bullets = Group()	
	# Main loop
	while True:
		# Watch for keyboard and mouse events
		fn.check_events(game_settings, screen, rocket, bullets)
		rocket.update()
		fn.update_bullets(bullets)				
		fn.update_screen(game_settings, screen, rocket, bullets)
		
run_game()
