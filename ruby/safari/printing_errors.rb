# printing_errors to log
def error_logger(e)
	File.open('/root/myprog/ruby/safari/error_log.txt', 'a') do |file|
		file.puts e
	end
end

begin 
	puts nil * 10
rescue StandardError => e
	error_logger("Error: #{e}")
end
