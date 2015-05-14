#!/usr/bin/python
breakfast_special="Omelet"
breakfast_notes="contains cheese"
lunch_special="patty melt"
lunch_notes="with teriyaki sause"
dinner_special="buffalo steak"
dinner_notes="top loin"

meal_time=raw_input('Which mealtime do you want? [breakfast, lunch, dinner]')
print 'Specials for {0}:'.format(meal_time)
if meal_time == 'breakfast':
    print breakfast_special
    print breakfast_notes
elif meal_time == 'lunch':
    print lunch_special
    print lunch_notes
elif meal_time == 'dinner':
    print dinner_special
    print dinner_notes
else:
    print 'Sorry, {0} isn\'t valid.'.format(meal_time)
