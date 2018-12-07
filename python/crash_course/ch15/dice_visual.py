#die_visual.py
import pygal
from die import Die

# Create two D6 dice.
die_1 = Die()
die_2 = Die()

# Make some rolls, and store results in a list.
#results = []
#for roll_num in range(1000):
#	result = die_1.roll() + die_2.roll()
#	results.append(result)
results = [ die_1.roll() + die_2.roll() for roll_num in range(1000) ]

# Analyze the results.
#frequencies = []
max_results = die_1.num_sides + die_2.num_sides
#for value in range(2, max_results+1):
#	frequency = results.count(value)
#	frequencies.append(frequency)
frequencies = [ results.count(value) for value in range(2, max_results+1) ]
		
#print(results)
print(frequencies)
# Visualize the results.
# A histogram is a bar chart showing how often certain results occur.
hist = pygal.Bar()

hist.title = "Results of rolling two D6 1000 times."
#hist.x_labels = ['2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12']
hist.x_labels = [ num for num in range(2, 13) ]
hist.x_title = "Result"
hist.y_title = "Frequency of Result"

hist.add('D6 + D6', frequencies)
hist.render_to_file('dice_visual.svg')


