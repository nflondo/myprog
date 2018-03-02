# 9-5

class User():
    
    def __init__(
            self, first_name, last_name, 
            age, city, zip_code,
            login_attempts
            ):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
        self.city = city
        self.zip_code = zip_code
        self.login_attempts = login_attempts
        
    def describe_user(self):
        print("Name: "+ self.first_name.title() + " " + 
            self.last_name.title())
        print("Age: " + self.age )
        print("City: " + self.city + "\tZip Code: " + self.zip_code)
        
    def greet_user(self):
        print("\nWelcome " + self.first_name.title() + " " + 
            self.last_name.title())
            
    def increment_login_attempts(self):
        self.login_attempts += 1
        
    def reset_login_attempts(self):
        self.login_attempts = 0
        
user1 = User('julio', 'iglesias', 69, 'madrid', '98743', 2)
user1.increment_login_attempts()
user1.increment_login_attempts()
user1.increment_login_attempts()
user1.increment_login_attempts()
print(user1.first_name +" "+ str(user1.login_attempts))
user1.reset_login_attempts()
print(user1.first_name +" "+ str(user1.login_attempts))
