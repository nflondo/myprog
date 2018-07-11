# empty_screen
import pygame

def run_game():
	#Initialize and create screen project
	pygame.init()
	
	screen = pygame.display.set_mode((1200, 800))
	pygame.display.set_caption("Empty game")
	
	# Set bg color
	bg_color = (230, 230, 230)
	
	# Main loop for game
	while True:
		# Watch for keyboard and mouse events
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				sys.exit()
			elif event.type == pygame.KEYDOWN:
				print(event.key)
		
		# Redraw screen during each pass through the loop
		screen.fill(bg_color)
				
		# Make the most recently drawn screen visible
		pygame.display.flip()
	
run_game()
