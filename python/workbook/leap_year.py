#!/usr/bin/python3
# The time required for the Earth to orbit the Sun is slightly more than 365 days
# so an extra day, February 29, is included in some years to correct for this
# difference.  Such years are referred to as leap years.  The rules for deter-
# mining whether or not a year is a leap year follow:
# - Any year that is divisible by 400 is a leap year
# - Of the remaining years, any year that is divisible by 100 is not a leap year
# - Of the remaining years, any year that is divisible by 4 is a leap year
# - All other years are not leap years
def leap_year_check(year):
    if (year % 400) == 0:
#        print("year/400")
        return True
    elif (year % 100) == 0:
        return False
    elif (year % 4) == 0:
        return True
    else:
        return False

def main():
    year = int(input("Enter year to check: "))
    if leap_year_check(year):
        print("The year %d IS a leap year" % year)
    else:
        print("The year %d is NOT a leap year" % year)

if __name__ == "__main__":
    main()
