# raindrop game functions
import sys
import pygame
from drop import Drop

def get_number_rows(game_settings, drop_height):
	"""Determine the number of rows of aliens that fit on the screen."""
	available_space_y = (game_settings.screen_height - (4 * drop_height))
	number_rows = int(available_space_y / (2 * drop_height))
	return number_rows

def get_number_drops_x(game_settings, drop_width):
	"""Determine the number of drops that fit in a row."""
	available_space_x = game_settings.screen_width - 2 * drop_width
	number_drops_x = int(available_space_x / (2 * drop_width))
	return number_drops_x

def create_drop(game_settings, screen, drops, drop_number, row_number):
	"""Create a drop and place it in the row."""
	drop = Drop(game_settings, screen)
	drop_width = drop.rect.width
	drop.x = drop_width + 2 * drop_width * drop_number
	drop.rect.x = drop.x
	drop.rect.y = drop.rect.height + 2 * drop.rect.height * row_number
	drops.add(drop)	

def create_fleet(game_settings, screen, drops):
	"""Create a full fleet of aliens."""
	drop = Drop(game_settings, screen)
	# Create an alien and find the number of aliens in a row.
	# Spacing between each alien is equal to one alien width.
	number_drops_x = get_number_drops_x(game_settings, drop.rect.width)	
	number_rows = get_number_rows(game_settings, drop.rect.height)
	
	# Create the fleet of aliens.
	for row_number in range(number_rows):
		# Create the first row of aliens.
		for drop_number in range(number_drops_x):
			# Create an alien and place it in the row.
			create_drop(game_settings, screen, drops, drop_number, row_number)
			
def update_drops(game_settings, screen, drops):
	"""Check if the fleet is at an edge and then update the positions of all
	aliens in the fleet"""
	check_fleet_edges(game_settings, screen, drops)
	drops.update()		
	
def check_fleet_edges(game_settings, screen, drops):
	"""Respond appropriately if any aliens have reached an edge."""
	# Get rid of bullets that have disappeared.
	for drop in drops.copy():
		if drop.rect.bottom >= 800:
			drops.remove(drop)
	
	print(len(drops))
	if len(drops) == 0:
		# Destroy existing bullets and create new fleet.
#		drops.empty()
		create_fleet(game_settings, screen, drops)	
'''
	for drop in drops.sprites():
		if drop.check_edges():
			# Get rid of bullets that have disappeared.
			for bullet in bullets.copy():
				if bullet.rect.bottom <= 0:
					bullets.remove(bullet)
			#print(len(bullets))
			break	
			create_fleet(game_settings, screen, drops)	
'''
def change_fleet_direction(game_settings, drops):
	"""Drop the entire fleet and change the fleet's direction."""
	for drop in drops.sprites():
		drop.rect.y += game_settings.fleet_drop_speed
	game_settings.fleet_direction *= -1
	
def update_screen(game_settings, screen, drops):
	"""Updates imges on the screen and flip to the new screen."""
	# Redraw the screen during each pass through the loop.
	screen.fill(game_settings.bg_color)
	# Redraw all bullets behind ship and aliens.
#	for bullet in bullets.sprites():
#		bullet.draw_bullet()
#	ship.blitme()	
#	alien.blitme()	
	drops.draw(screen)
	# Make the most recently drawn screen visible.
	pygame.display.flip()	
	

