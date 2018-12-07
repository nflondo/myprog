#die_visual.py
import pygal
from die import Die

# Create a D6 and D10 dice.
die_1 = Die()
die_2 = Die(10)

# Make some rolls, and store results in a list.
results = []
for roll_num in range(50000):
	result = die_1.roll() + die_2.roll()
	results.append(result)

# Analyze the results.
frequencies = []
max_results = die_1.num_sides + die_2.num_sides

for value in range(2, max_results+1):
	frequency = results.count(value)
	frequencies.append(frequency)
		
#print(results)
print(frequencies)
# Visualize the results.
# A histogram is a bar chart showing how often certain results occur.
hist = pygal.Bar()

hist.title = "Results of rolling a D6 and a D10 50,000 times."
hist.x_labels = ['2', '3', '4', '5', '6', '7', '8', '9', '10', '11', 
	'12', '13', '14', '15', '16' ]
hist.x_title = "Result"
hist.y_title = "Frequency of Result"

hist.add('D6 + D10', frequencies)
hist.render_to_file('dice_visual.svg')


