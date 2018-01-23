guests = ['fernando', 'chuy', 'luis', 'cesar' ]
for guest in guests:
	print(guest.title() + " please come to my party")
	
unable_attend = 'cesar'
print(unable_attend)

guests.remove(unable_attend)
guests.append('oscar')	

print("*" * 10)
for guest in guests:
	print(guest.title() + " please come to my party")
	
guests.insert(0, 'alfonso')
guests.insert(1, 'chacho')
guests.append('anna')	

print("*" * 10)
for guest in guests:
	print(guest.title() + " please come to my party")

print("Can only invite 2 people for dinner====")

while len(guests) != 2:
	removed_guest = guests.pop()
	print("Sorry, " + removed_guest.title() + " I can't invite you to"
		" dinner.")
		
print("*" * 10)
for guest in guests:
	print(guest.title() + " please come to my party")

del guests[1]
del guests[0]

print (guests)
