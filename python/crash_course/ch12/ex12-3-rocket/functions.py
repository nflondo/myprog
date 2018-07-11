# functions
import sys
import pygame

def check_events(rocket):
	"""Respond to keypresses and mouse events."""
	#Watch for keyboard and mouse events.
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			sys.exit()
		elif event.type == pygame.KEYDOWN:
			check_keydown_events(event, rocket)
		elif event.type == pygame.KEYUP:
			check_keyup_events(event, rocket)	
			
def check_keydown_events(event, rocket):
	"""Respond to keypresses."""
	if event.key == pygame.K_RIGHT:
		rocket.moving_right = True
	elif event.key == pygame.K_LEFT:
		rocket.moving_left = True
	elif event.key == pygame.K_UP:
		rocket.moving_up = True
	elif event.key == pygame.K_DOWN:
		rocket.moving_down = True
				
def check_keyup_events(event, rocket):
	"""Respond to key releases."""						
	if event.key == pygame.K_RIGHT:
		rocket.moving_right = False
	elif event.key == pygame.K_LEFT:
		rocket.moving_left = False
	elif event.key == pygame.K_UP:
		rocket.moving_up = False
	elif event.key == pygame.K_DOWN:
		rocket.moving_down = False
	
		
def update_screen(game_settings, screen, rocket):
	"""Updates imges on the screen and flip to the new screen."""
	# Redraw the screen during each pass through the loop.
	screen.fill(game_settings.bg_color)
	rocket.blitme()		
	# Make the most recently drawn screen visible.
	pygame.display.flip()
