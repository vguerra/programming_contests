#!/usr/bin/python

#Victor Guerra <vguerra@gmail.com>
#20141125

#https://www.hackerrank.com/challenges/predicting-house-prices

from sklearn import linear_model

(F, N) = raw_input().split()

F = int(F)
N = int(N)

features = []
prices = []
for x in range(N):
    arr = [float(a) for a in raw_input().split()]
    features.append(arr[0 : F])
    prices.append(arr[F])

#print features
clf = linear_model.LinearRegression();
clf.fit(features, prices);

T = int(raw_input())

X = [[float(a) for a in raw_input().split()] for b in range(T)]

for y in clf.predict(X):
    print y
