from car import ElectricCar

my_prius = ElectricCar('toyota', 'prius', 2017)

print(my_prius.get_descriptive_name())
my_prius.battery.describe_battery()
my_prius.battery.get_range()

