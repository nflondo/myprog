##inheritance
class ApiConnector
	attr_accessor :title, :description, :url #setters and getters
	
	# everything here gets run when a new object is create
	def initialize(title: sometitle, description: some_description, url: url = "yahoo.com") # url has a default value
		@title = title
		@description = description
		@url = url	
		secret_method	
	end	
	
	def api_logger
		puts "API Connector starting.."
	end
	
	def testing_initializers
		puts @title
		puts @description
		puts @url
	end
	
#	private  # private method
	protected  # protected method. Not very common
		def secret_method
			puts "A secret message from inside secret_method"
		end
	
end #end class

class SmsConnector < ApiConnector # < means inherits from class ApiConnector
	def send_sms
		puts "Sending sms..."
		`curl -X POST -d "notification[title]=#{@title}" -d "notification[url]
			=http://edutechional-resty.herokuapp.com/posts/42" #{@url}`
	end
end

class PhoneConnector < ApiConnector # < means inherits from class ApiConnector
	def api_logger # Polymorphism is when child method overrides parent one.
		super # will call the parent's method, so it runs both
		puts "Phone call API connection starting..."
	end
	def send_phone_call
		puts "Sending phone call..."
	end
end

class MailConnector < ApiConnector # < means inherits from class ApiConnector
	def send_email
		puts "Sending email..."
	end
end

#sms = SmsConnector.new(title: "sms object", description: "cool sms object", url: "http://edutechional-smsy.herokuapp.com/notifications")
phone = PhoneConnector.new(title: "sms object", description: "cool sms object", url: "suse.com")
email = MailConnector.new(title: "sms object", description: "cool sms object", url: "suse.com")

#sms.send_sms
phone.send_phone_call
email.send_email
phone.api_logger
