#scatter_squares.py
import matplotlib.pyplot as plt

x_values = list(range(1, 1001))
y_values = [x**2 for x in x_values]
#x_values = [1, 2, 3, 4, 5]
#y_values = [1, 4, 9, 16, 25]

#plt.scatter(2, 4, s=200)
# You can pass the RGB color model.  Values closer to 0 produce dark colors
# values closer to 1 produce lighter colors.
#plt.scatter(x_values, y_values, c=(0.5, 0, 0.8), edgecolor='none', s=40)
plt.scatter(x_values, y_values, c=(y_values), cmap=plt.cm.Blues,
	edgecolor='none', s=40)

# Set chart title and label axes.
plt.title("Square Numbers", fontsize=24)
plt.xlabel("Value", fontsize=14)
plt.ylabel("Square of Value", fontsize=14)

# Set size of tick labels.
#plt.tick_params(axis='both', which='major', labelsize=14)

# Set the range for each axis.
plt.axis([0, 1100, 0, 1100000])

plt.show()
#plt.savefig('squares_plot.png', bbox_inches='tight')
