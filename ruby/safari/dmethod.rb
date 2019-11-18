#metaprogramming mechanisn the define method
class Author
#	define_method("some_method") do
#		puts "Some details"
#	end

	#def fiction_details(arg)
		#puts "Fiction"
		#puts arg
		#puts "asdfsd"
	#end

	#def coding_details(arg)
		#puts "coding"
		#puts arg
		#puts "asdfsd"
	#end
	
	#def history_details(arg)
		#puts "history"
		#puts arg
		#puts "asdfsd"
	#end
	
	genres = %w(fiction coding history) # array of strings
	
	genres.each do |genre|
		define_method("#{genre}_details") do |arg|
			puts "Genre: #{genre}"
			puts arg
			puts genre.object_id
		end
	end
end

author = Author.new
#author.some_method
author.coding_details("Cal Newport")
author.fiction_details("John Grisham")
p author.respond_to?(:fiction_details)
