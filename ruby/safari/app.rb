require 'sinatra'

class HiSinatra < Sinatra::Base
	get '/' do
		"Hey Sinatra, second attempt!"
	end
	
	get '/:age' do
		"Hi, I'm #{params[:age]} years old"
	end
end
