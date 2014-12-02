#!/usr/bin/python

#Victor Guerra <vguerra@gmail.com>
#20141127

#https://www.hackerrank.com/challenges/battery

import sys
from sklearn.linear_model import LinearRegression


file = open('trainingdata.txt')
data = [map(float, line.rstrip().split(',')) for line in file]
file.close()

charge_times = [[x[0]] for x in data if x[0] < 4]
battery_life = [x[1] for x in data if x[1] < 8]

clf = LinearRegression()
clf.fit(charge_times, battery_life)

charge_time = float(raw_input())
if charge_time >= 4.00:
    print 8.00
else:
    print "{0:0.2f}".format(clf.predict(charge_time)[0])
