class Array
	def quicksort
		return[] if empty?
		
		#[34,2,1,5,3] pick a pivot element, random
		#[34,2,5,3]
		# left = [34, 2]
		# right = [5, 3]
		pivot = delete_at(rand(size))  # will choose element to be the pivot value
		left, right = partition(&pivot.method(:>)) # partition is an array method
		
		return *left.quicksort, pivot, *right.quicksort # returning splat argument			
	end
end

arr = [34,2,1,5,3]
p arr.quicksort
