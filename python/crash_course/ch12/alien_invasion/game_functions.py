import sys

import pygame

def check_events(ship):
	"""Respond to keypresses and mouse events."""
	#Watch for keyboard and mouse events.
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			sys.exit()
		elif event.type == pygame.KEYDOWN:
			if event.key == pygame.K_RIGHT:
				ship.moving_right = True
				
		elif event.type == pygame.KEYUP:
			if event.key == pygame.K_RIGHT:
				ship.moving_right = False
				#Move the ship to the right.
				#ship.rect.centerx += 1
				
def update_screen(ai_settings, screen, ship):
	"""Updates imges on the screen and flip to the new screen."""
	# Redraw the screen during each pass through the loop.
	screen.fill(ai_settings.bg_color)
	ship.blitme()
		
	# Make the most recently drawn screen visible.
	pygame.display.flip()
	

