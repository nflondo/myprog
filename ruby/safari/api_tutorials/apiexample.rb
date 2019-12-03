require 'rubygems'
require 'httparty'

#class EdutechionalResty
	#include HTTParty
	#base_uri "edutechional-resty.herokuapp.com/"
	
	#def posts
		#self.class.get('/posts.json')
	#end
#end

#edutechional_resty = EdutechionalResty.new
#puts edutechional_resty.posts

#response = HTTParty.get('http://api.stackexchange.com/2.2/questions?site=stackoverflow')

# puts response.body  # grabs the whole thing
#puts response.code # only grab the status code
#puts response.message # returns OK
#puts response.headers.inspect # gets back the headers

class StackExchange
include HTTParty
	base_uri 'api.stackexchange.com'
	
	def initialize(service, page)
		@options = { query: {site: service}}
	end
	
	def questions
		self.class.get('/2.2/questions', @options) # /2.2/questions is the API end point
	end	
	
	def users
		self.class.get('/2.2/users', @options)
	end
end

stack_exchange = StackExchange.new('stackoverflow', 1) # This is the service name from API doc
puts stack_exchange.questions
