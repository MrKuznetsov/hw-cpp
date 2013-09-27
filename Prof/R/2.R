#getting count of deaths from road with number 20
road[20,"deaths"]
#getting count of population denesty from road with number 20
road[20,"popden"]
#make a new table with roads where number of deaths more than 1000
deaths <- subset(road, deaths>1000)
#getting count of roads where number of deaths more than 1000
nrow(deaths)
#max temerature
max(deaths[,"temp"])
#min temerature
min(deaths[,"temp])