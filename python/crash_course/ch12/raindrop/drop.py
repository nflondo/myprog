# alien class
import pygame
from pygame.sprite import Sprite

class Drop(Sprite):
	"""A class to represent a single alien in the fleet."""
	
	def __init__(self, game_settings, screen):
		"""Initialize the alien and set its starting position."""
		super(Drop, self).__init__()
		self.screen = screen
		self.game_settings = game_settings
		
		# Load the drop image and set its rect attribute.
		self.image = pygame.image.load('images/raindrop.bmp')
		self.rect = self.image.get_rect()
		
		# Start each new alien near the top left of the screen.
		self.rect.x = self.rect.width
		self.rect.y = self.rect.height
		
		# Store the alien's exact position.
		self.x = float(self.rect.x)
		self.y = float(self.rect.y)
		
	def blitme(self):
		"""Draw the alien at its current location."""
		self.screen.blit(self.image, self.rect)

	def update(self):
#		"""Move the alien right."""
#		self.x += self.ai_settings.alien_speed_factor		
		"""Move the alien right or left."""
#		self.x += (self.game_settings.drop_speed_factor * self.game_settings.fleet_direction)
#		self.rect.x = self.x
		self.y += self.game_settings.drop_speed_factor
		self.rect.y = self.y
		
#			def update(self):
		"""Move the bullet up the screen."""
		# Update the decimal position of the bullet.
#		self.y -= self.speed_factor
		# Update the rect position.
#		self.rect.y = self.y
		
	def check_edges(self):
		"""Return True if alien is at edge of screen."""
		screen_rect = self.screen.get_rect()
#		if self.rect.bottom >= screen_rect.bottom:
		print(self.rect)
		if self.rect.bottom >= 800:
			return True
		
		
