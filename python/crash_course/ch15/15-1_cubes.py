#15-1 Cubes
# Plot the first five cubic numbers, and then plot the firest 5000 cubic numbers
import matplotlib.pyplot as plt

x_values = list(range(1, 5000))
y_values = [x**3 for x in x_values]

plt.scatter(x_values, y_values, c=(y_values), cmap=plt.cm.Blues, 
	edgecolor='none', s=40)

plt.show()
