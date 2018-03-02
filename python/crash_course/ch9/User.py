# 9-3

class User():
    
    def __init__(self, first_name, last_name, age, city, zip_code):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
        self.city = city
        self.zip_code = zip_code
        
    def describe_user(self):
        print("Name: "+ self.first_name.title() + " " + 
            self.last_name.title())
        print("Age: " + self.age )
        print("City: " + self.city + "\tZip Code: " + self.zip_code)
        
    def greet_user(self):
        print("\nWelcome " + self.first_name.title() + " " + 
            self.last_name.title())
        
user1 = User('alberto', 'planas', '30', 'madrid', '98743')
user2 = User('bruce', 'rogers', '50', 'benjamin', '84651')
user3 = User('Martin', 'Johnson', '45', 'Cleveland', '76876')

user1.greet_user()
user1.describe_user()
user2.greet_user()
user2.describe_user()
user3.greet_user()
user3.describe_user()
