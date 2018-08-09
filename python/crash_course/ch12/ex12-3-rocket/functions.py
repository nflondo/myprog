# functions
import sys
import pygame
from bullet import Bullet
from alien import Alien

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
	
		
def update_screen(game_settings, screen, rocket, aliens, bullets):
	"""Updates imges on the screen and flip to the new screen."""
	# Redraw the screen during each pass through the loop.
	screen.fill(game_settings.bg_color)
	# Redraw all bullets behind ship and aliens.
	for bullet in bullets.sprites():
		bullet.draw_bullet()
	rocket.blitme()	
	rocket.blitme()		
	aliens.draw(screen)
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

def get_number_rows(game_settings, rocket_height, alien_height):
	"""Determine the number of rows of aliens that fit on the screen."""
	available_space_y = (game_settings.screen_height - (3 * alien_height) - rocket_height)
	number_rows = int(available_space_y / (2 * alien_height))
	return number_rows

def get_number_aliens_x(game_settings, alien_width):
	"""Determine the number of aliens that fit in a row."""
	available_space_x = game_settings.screen_width - 2 * alien_width
	number_aliens_x = int(available_space_x / (2 * alien_width))
	return number_aliens_x
	
def create_alien(game_settings, screen, aliens, alien_number, row_number):
	"""Create an alien and place it in the row."""
	alien = Alien(game_settings, screen)
	alien_width = alien.rect.width
	alien.x = alien_width + 2 * alien_width * alien_number
	alien.rect.x = alien.x
	alien.rect.y = alien.rect.height + 2 * alien.rect.height * row_number
	aliens.add(alien)
	
def create_fleet(game_settings, screen, rocket, aliens):
	"""Create a full fleet of aliens."""
	alien = Alien(game_settings, screen)
	# Create an alien and find the number of aliens in a row.
	# Spacing between each alien is equal to one alien width.
	number_aliens_x = get_number_aliens_x(game_settings, alien.rect.width)	
	number_rows = get_number_rows(game_settings, rocket.rect.height, alien.rect.height)
	
	# Create the fleet of aliens.
	for row_number in range(number_rows):
		# Create the first row of aliens.
		for alien_number in range(number_aliens_x):
			# Create an alien and place it in the row.
			create_alien(game_settings, screen, aliens, alien_number, row_number)
