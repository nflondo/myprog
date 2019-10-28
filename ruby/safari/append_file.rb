# Appending to a file
10.times do
	sleep 1 # one sec
	puts "Record saved..."
	File.open("/home/nmunoz/myprog/ruby/safari/server_logs.txt", "a") \
		{|f| f.puts "Server started at: #{Time.new}"}
end
