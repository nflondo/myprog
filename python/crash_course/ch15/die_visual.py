#die_visual.py
import pygal
from die import Die

# Create a D6.
die = Die()

# Make some rolls, and store results in a list.
#results = []
#for roll_num in range(1000):
#	result = die.roll()
#	results.append(result)
results=[ die.roll() for result in range(1000) ]

# Analyze the results.
#frequencies = []
#for value in range(1, die.num_sides+1):
#	frequency = results.count(value)
#	frequencies.append(frequency)
frequencies = [ results.count(value) for value in range(1, die.num_sides+1) ]		
#print(results)
print(frequencies)
# Visualize the results.
# A histogram is a bar chart showing how often certain results occur.
hist = pygal.Bar()

hist.title = "Results of rolling one D6 1000 times."
#hist.x_labels = ['1', '2', '3', '4', '5', '6']
hist.x_labels = [ num for num in range(1, 7) ]
hist.x_title = "Result"
hist.y_title = "Frequency of Result"

hist.add('D6', frequencies)
hist.render_to_file('die_visual.svg')


