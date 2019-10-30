#error handling
begin
#	puts nil + 10
	puts 8/0
#rescue ZeroDivisionError => e
rescue StandardError => e  # This captures everything
	puts "error occurred: #{e}"
end
