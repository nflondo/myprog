import pygame
from pygame.sprite import Group
from settings import Settings
from ship import Ship
#from alien import Alien
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
	
	# Make a ship, a group of bullets, and a group of aliens.
	ship = Ship(ai_settings, screen)	
	# Make a group to store bullets in.
	bullets = Group()
	aliens = Group()
	# Make an alien
#	alien = Alien(ai_settings, screen)
	# Create the fleet of aliens.
	gf.create_fleet(ai_settings, screen, ship, aliens)
		
	# Start the main loop for the game.
	while True:
		#gf.check_events(ship)
		gf.check_events(ai_settings, screen, ship, bullets)
		ship.update()
		gf.update_bullets(bullets)		
		gf.update_screen(ai_settings, screen, ship, aliens, bullets)		
		
run_game()
