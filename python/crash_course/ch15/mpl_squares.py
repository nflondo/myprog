#mpl_squares.py
import matplotlib.pyplot as plt
import matplotlib.rcsetup as rcsetup
print(rcsetup.all_backends)

squares = [1,4,9,16,25]
plt.plot(squares, linewidth=5)

# Set chart title and label axes.
plt.title("Square Numbers", fontsize=24)
plt.xlabel("Value", fontsize=14)
plt.ylabel("squre of Value", fontsize=14)

# Set size of tick labels.
plt.tick_params(axis='both', labelsize=14)

plt.show()


