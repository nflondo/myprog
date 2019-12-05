#apiexample2.rb

require 'rubygems'
require 'httparty'

class EdutechionalResty
	include HTTParty
	base_uri "edutechional-resty.herokuapp.com/"
	
	def posts
		self.class.get('/posts.json')
	end
end

edutechional_resty = EdutechionalResty.new
#puts edutechional_resty.posts

edutechional_resty.posts.each do |post|
	#puts post
	p "Title: #{post['title']} | Description: #{'description'}"
	# enter data in db supposing it's a rails application
	#Post.create(title: post['title'], description: post['description'])
end

#response = HTTParty.get('http://api.stackexchange.com/2.2/questions?site=stackoverflow')
