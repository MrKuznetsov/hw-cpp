library("MASS")

setwd("c:/programming/hw-cpp/Prof/R/Task3/")#set working directory

#set pdf file where we are drawing
pdf(file="example.pdf", width=11.6, height=8.9);
#attach data to workspace
attach(Cars93)
#set 2 graphics to draw
par(mfrow = c(1, 2), oma = c(1, 0, 0, 0));
#draw a box
boxplot(Price ~ DriveTrain,  col = c("yellow", "pink", "blue"), main = "(a)",
        varwidth = TRUE, xlab = "Drive train type", ylab = "Price(in $1,000)")
#draw points     
plot(xlim = c(60, 300), ylim = c(8, 26), Price ~ Horsepower, col = c("yellow", "pink", "blue"),
     main = "(b)", pch=c(15,16,17), xlab="Horsepower", ylab="Price(in $1,000)");
#draw legend
legend(220, 15, c("4WD","Front","Rear"),pch = c(15, 16, 17), col = c("yellow", "pink", "blue"));
#draw text
mtext("Picture. This is very interesting picture.a) represents very beautiful boxplots, b) represents very beautiful points.",1,0,outer=TRUE);
dev.off();