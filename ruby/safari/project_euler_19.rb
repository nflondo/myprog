# Problem 19 projecteuler.net
# February has 28 days except on leap years when it has 29.  A leap years occurs
# on any year evenly divisible by 4, but not on a century unless it is divisible by 400
require 'date'

start_date = Time.local(1901) # will give you jan 1
#p start_date
end_date = Time.local(2000,12,31)
#p end_date
sunday_counter = 0

while end_date >= start_date
	# string from time method. name day of week
	if end_date.strftime("%A") == "Sunday" && end_date.strftime("%d") == "01"
		sunday_counter += 1
	end
	end_date -= 86400
end

p sunday_counter
