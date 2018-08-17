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
		
	def blitme(self):
		"""Draw the alien at its current location."""
		self.screen.blit(self.image, self.rect)

	def update(self):
#		"""Move the alien right."""
#		self.x += self.ai_settings.alien_speed_factor		
		"""Move the alien right or left."""
		self.x += (self.ai_settings.alien_speed_factor * self.ai_settings.fleet_direction)
		self.rect.x = self.x
		
	def check_edges(self):
		"""Return True if alien is at edge of screen."""
		screen_rect = self.screen.get_rect()
		if self.rect.right >= screen_rect.right:
			return True
		elif self.rect.left <=0:
			return True		
	
		
