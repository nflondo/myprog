#https://projecteuler.net/problem=2
class ProjectEulerTwo
	def initialize(max)
		# Instance variables
		@num_1 = 0
		@num_2 = 1
		@i = 0
		@sum = 0		
		@max = max
	end
	
	def even_fibonacci
		while @i <= @max
			@i = @num_1 + @num_2
		 
			@sum += @i if @i % 2 == 0 # %2 == 0 gives you even numbers
			# swapping the values here
			@num_1 = @num_2  
			
			@num_2 = @i
		end
		@sum
	end
end

result = ProjectEulerTwo.new(4_000_000)
p result.even_fibonacci
