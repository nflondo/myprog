## OO Programming
class ApiConnector
	attr_accessor :title, :description, :url #setters and getters
	
	def test_method
		puts "In test_method"
	end
	
	# everything here gets run when a new object is create
	def initialize(title: sometitle, description: some_description, url: url = "yahoo.com") # url has a default value
		@title = title
		@description = description
		@url = url		
	end	
	
	def testing_initializers
		puts @title
		puts @description
		puts @url
	end
end #end class

#api = ApiConnector.new
# Add attribute
#api.url = "http://google.com/"
#puts api.url

#api.test_method

api = ApiConnector.new(title: "My title", description: "my description") # don't have to pass default val
api.testing_initializers
