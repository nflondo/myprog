# 12-2 
# this controls the position of the image ( controller)
import pygame


class Controller():
	
	def __init__(self, screen):
		"""Initialize the ship and set its starting position."""
		self.screen = screen
		
		# Load the ship image and get its rect.
		self.image = pygame.image.load('images/controller3.png')
		self.rect = self.image.get_rect()
		self.screen_rect = screen.get_rect()
		
		# Start each new ship at the bottom center of the screen.
		self.rect.centerx = self.screen_rect.centerx
		self.rect.bottom = self.screen_rect.bottom
		
	def blitme(self):
		"""Draw the ship at its curent location."""
		self.screen.blit(self.image, self.rect)
