# 12-2 
# this controls the position of the image ( controller)
import pygame

class Rocket():
	
	def __init__(self, game_settings, screen):
		"""Initialize the rocket and set its starting position."""
		self.screen = screen
		self.game_settings = game_settings
		# Load the rocket image and get its rect.
		self.image = pygame.image.load('images/ship.bmp')
		self.rect = self.image.get_rect()
		self.screen_rect = screen.get_rect()
		
		# Start each new rocket at the middle center of the screen.
		self.rect.centerx = self.screen_rect.centerx
#		self.rect.bottom = self.screen_rect.bottom
		self.rect.centery = self.screen_rect.centery
		
		# Movement flag
		self.moving_right = False
		self.moving_left = False
		self.moving_up = False
		self.moving_down = False
		
	def update(self):
		"""Update the rocket's position based on the movement flag."""
		# Update the rocket's center value, not the rect.
		if self.moving_right and self.rect.right < self.screen_rect.right:
		#if self.moving_right:
			self.rect.centerx += 1
		if self.moving_left and self.rect.left > 0:
		#if self.moving_left:
			self.rect.centerx -= 1
		if self.moving_up and self.rect.top > 0:
		#if self.moving_up:
			self.rect.centery -= 1
		if self.moving_down and self.rect.bottom < self.screen_rect.bottom:
			self.rect.centery += 1
		# Update rect object from self.center
		#self.rect.centerx = self.center
		
	def blitme(self):
		"""Draw the rocket at its curent location."""
		self.screen.blit(self.image, self.rect)
