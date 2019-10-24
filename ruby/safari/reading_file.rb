#reading a file

team_one = File.read("/home/nmunoz/myprog/ruby/safari/teams.txt")
team_two = File.read("/home/nmunoz/myprog/ruby/safari/other_teams.txt")
# converts it into array
team_master = team_one.split(', ') + team_two.split(', ')
team_master.each do |team|
	p team.upcase
end

