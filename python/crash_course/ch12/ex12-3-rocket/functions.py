# functions
import sys
import pygame
from bullet import Bullet

def check_events(game_settings, screen, rocket, bullets):
	"""Respond to keypresses and mouse events."""
	#Watch for keyboard and mouse events.
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			sys.exit()
		elif event.type == pygame.KEYDOWN:
			check_keydown_events(event, game_settings, screen, rocket, bullets)
		elif event.type == pygame.KEYUP:
			check_keyup_events(event, rocket)	
			
def check_keydown_events(event, game_settings, screen, rocket, bullets):
	"""Respond to keypresses."""
	if event.key == pygame.K_RIGHT:
		rocket.moving_right = True
	elif event.key == pygame.K_LEFT:
		rocket.moving_left = True
	elif event.key == pygame.K_UP:
		rocket.moving_up = True
	elif event.key == pygame.K_DOWN:
		rocket.moving_down = True
	elif event.key == pygame.K_SPACE:
		fire_bullet(game_settings, screen, rocket, bullets)

def fire_bullet(game_settings, screen, rocket, bullets):
	"""Fire a bullet if limit not reached yet."""
	# Create a new bullet and add it to the bullets group.
	if len(bullets) < game_settings.bullets_allowed:
		new_bullet = Bullet(game_settings, screen, rocket)
		bullets.add(new_bullet)	
				
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
	
		
def update_screen(game_settings, screen, rocket, bullets):
	"""Updates imges on the screen and flip to the new screen."""
	# Redraw the screen during each pass through the loop.
	screen.fill(game_settings.bg_color)
	# Redraw all bullets behind ship and aliens.
	for bullet in bullets.sprites():
		bullet.draw_bullet()
	rocket.blitme()	
	rocket.blitme()		
	# Make the most recently drawn screen visible.
	pygame.display.flip()

def update_bullets(bullets):
	"""Update position of bullets and get rid of old bullets."""
	bullets.update()
	
	# Get rid of bullets that have disappeared.
	for bullet in bullets.copy():
	#	if bullet.rect.bottom <= 0:
		if bullet.rect.right > 1200:
			bullets.remove(bullet)
	#print(len(bullets))
