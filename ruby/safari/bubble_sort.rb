#algorithms
def bubble_sort(array)
	n = array.length
	
	loop do
		# [1,4,1,3,4,1,3,3]
		# [1,1,4,3,4,1,3,3]
		# [1,1,3,4,4,1,3,3]
		# [1,1,3,4,4,1,3,3]
		# [1,1,3,4,1,4,3,3]
		# [1,1,3,4,1,3,4,3]
		# [1,1,3,4,1,3,3,4]
		# [1,1,3,4,1,3,3,4]
		# [1,1,3,1,4,3,3,4]
		# [1,1,3,1,3,4,3,4]
		# [1,1,3,1,3,3,4,4]
		# [1,1,1,3,3,3,4,4]
		
		swapped = false
		
		(n-1).times do |i|  #From 0 to n-1 number. It iterates the given block.
			if array[i] > array[i + 1]
				array[i], array[i + 1] = array[i +1], array[i]
				swapped = true
			end
		end	
		
		break if not swapped						
	end
	
	array
end

a = [1,4,1,3,4,1,3,3]
p bubble_sort(a)
