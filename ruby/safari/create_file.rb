#creating a file
# r - reading
# a - appending
# w - writing
# w+ - reading and writing
# a+ - open a file for reading and appending
# r+ - open a file for updating, both reading and writing
File.open("/home/nmunoz/myprog/ruby/safari/teams.txt", 'w+') \
	{|f| f.write("Twins, Astros, Mets, Yankees")}

# Another way of doing it.
file_to_save = File.new("/home/nmunoz/myprog/ruby/safari/other_teams.txt", 'w+')
file_to_save.puts("A's, Diamondbacks, Marineers, Marlins")
file_to_save.close


