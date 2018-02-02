# checking usernames
current_users = ['maure', 'logan', 'allen', 'craig', 'Drew']
new_users = ['john', 'max', 'matt', 'CRAIG', 'drew']

for user in (new_user.lower() for new_user in new_users):    
    if user in (name.lower() for name in current_users):
        print("Already taken, please enter a new username")
    else:
        print("Username available !!")
        
# Ordinal numbers
ordinal = [1,2,3,4,5,6,7,8,9]
for num in ordinal:
    if num == 1:
        print(str(num) + "st")
    elif num == 2:
        print(str(num) + "nd")
    elif num == 3:
        print(str(num) + "rd")
    else:
        print(str(num) + "th")        

