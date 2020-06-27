# PREDICTORv1.0
Application for predicting football results 

This is an application developped using C++ and the framework Qt5

This application uses quite a lot of Qtś features.

# Process

Well to put it simply, I use Poisson distribution to predict how many occurences a certain number of goals is bound to happen (i.e scored).

The calculation process is explained quite elaborately in this [beautiful article](https://help.smarkets.com/hc/en-gb/articles/115001457989-How-to-calculate-Poisson-distribution-for-football-betting) 

tl;dr: for a team, we need the ***average*** number of goals scored and conceded both home and away. We also need the average of goals scored in the league, also home and away. So if for a match, the *lambda* parameter, which serves as the average used for Poisson distribution, is calculated by multiplying these averages depending on the home and away team. The averages, which are the stats, are calculated using an Excel spreadsheet and stored in a database. 

Anyhow, the predictions are preferrably stored in a matrix like this:

![matrix](https://user-images.githubusercontent.com/61631857/85921855-32bbaa00-b877-11ea-8f5b-d7a026162a4d.png)

Now the most highly likely final result is the one with the highest associated probability, in the example above it's 2-0. Simple, right ?

# Implementation

The most important thing is the stats, which I calculated using a spreadsheet like this:

![matrix](https://user-images.githubusercontent.com/61631857/85921942-b70e2d00-b877-11ea-8feb-16c4f3589b44.png)

I then linked this (and other leagues done simlarly) to a database, then linked the database to Qt.

The calculations then are pretty easy, once one chooses the league, then the home/away teams, we retrieve the associated stats and calculate the poisson estimate for 0,...,6, storing them in a matrix, and displaying the highest number of predicted goals for each team. Just a bunch of `for` and `if` blocks.   

Here's the log, that I set to print some results: 

![Screenshot from 2020-06-27 13-27-24](https://user-images.githubusercontent.com/61631857/85922295-1a00c380-b87a-11ea-9496-f7916d162462.png)

# Interface

![Screenshot from 2020-06-27 13-23-31](https://user-images.githubusercontent.com/61631857/85922289-12411f00-b87a-11ea-9de8-05b1af750b5f.png)

![Screenshot from 2020-06-27 13-25-53](https://user-images.githubusercontent.com/61631857/85922291-14a37900-b87a-11ea-9704-38eacf44620e.png)

![Screenshot from 2020-06-27 13-26-17](https://user-images.githubusercontent.com/61631857/85922292-179e6980-b87a-11ea-9666-3c7e3ce5c714.png)







