odd_numbers = list(range(1,20,2))
for odd in odd_numbers:
	print(odd)

print("*" * 10)	
multiple_three = []
for multiple in range(3,31):
	multiple_three.append(multiple * 3)
	
for number in multiple_three:
	print(number)

print("*" * 10)	
cubes = []
for cube in range(1,11):
	cubes.append(cube ** 3)
	
for cube in cubes:
	print(cube)

print("*" * 10)	
cubes_comp = [cube ** 3 for cube in range(1,11) ]

for cube in cubes_comp:
	print(cube)
