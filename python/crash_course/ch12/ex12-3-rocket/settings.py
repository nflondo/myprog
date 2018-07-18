#12-3-settings.py
class Settings():
	"""A class to store settings for rocket exercise"""
	
	def __init__(self):
		"""Initialize game settings"""
		# Screen settings
		self.screen_width = 1200
		self.screen_height = 800
		self.bg_color = (0, 0, 255)
		
		# Bullet Settings
		self.bullet_speed_factor = 1
		self.bullet_width = 3
		self.bullet_height = 15
		self.bullet_color = 60, 60, 60
		self.bullets_allowed = 12
		

