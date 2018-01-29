num_list = []
for num in range(0,14,2):
	num_list.append(num)
print(num_list)
print("first three items:" + str(num_list[0:3])) 
print("three items from middle:" + str(num_list[2:5])) 
print("last three items:" + str(num_list[-3:])) 

print("*" * 10)
pizzas = ['pepperoni', 'meat', 'hawaiian']
friend_pizzas = pizzas[:]

pizzas.append('artchoke')
friend_pizzas.append('supreme')

print("My fav pizzas are:")
for pizza in pizzas:
	print(pizza)
	
print("Friend's fav pizzas are:")
for pizza in friend_pizzas:
	print(pizza)
