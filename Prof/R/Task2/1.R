setwd("c:/programming/hw-cpp/Prof/R/Task2/")#set working directory
#download table
download.file("http://archive.ics.uci.edu/ml/machine-learning-databases/wine-quality/winequality-red.csv",
              "data.dat");
#read table from file
table<-read.csv(file="data.dat", head=TRUE, sep=";")

#wineByQuality function
wineByQuality <- function(table, out)
{
  #from 0 to 10 quality
  for (i in 0:10)
  {
    #make a new table where quality == i & dettach column with quality(12)
   qi <- subset(table, quality == i, select = -12)
   #find mean value for all columns
   x <- apply(qi, 2, mean)
   #connect 2 tables
   data <- rbind(qi, x)
   #write table to file "i_out.csv"
   write.csv(data, paste0(i,"_",out,".csv"), row.names=FALSE)
  }
}

wineByQuality(table, "red")