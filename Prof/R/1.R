setwd("c:/programming/hw-cpp/Prof/R/")#set working directory
#download dataset to data.dat
download.file("https://data.medicare.gov/api/views/vs3q-rxc5/rows.csv?accessType=DOWNLOAD", "data.dat")
#read table from file
table<-read.csv(file="data.dat", head=TRUE, sep=",")
#trying to get dim and count of row and col
dim(table)
nrow(table)
ncol(table)
#getting class of table
class(table)
#getting class of vars
for (i in 1:ncol(table))
  print(class(table[,i]))
#not avalible items
#print table with the same dim
#true means that value not avalible, else false
is.na(table)