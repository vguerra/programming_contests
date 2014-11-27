#!/usr/bin/python

#Victor Guerra <vguerra@gmail.com>
#20141126

#https://www.hackerrank.com/challenges/predicting-office-space-price

from sklearn.preprocessing import PolynomialFeatures
from sklearn import linear_model

(F, N) = [int(x) for x in raw_input().split()]

test_data = [[float(x) for x in raw_input().split()] for i in range(N)]
features = [x[0:F] for x in test_data]
prices = [x[-1] for x in test_data]

poly = PolynomialFeatures(degree = 3)
poly_features = poly.fit_transform(features)

clf = linear_model.LinearRegression()
clf.fit(poly_features, prices)

T = int(raw_input())
X = [[float(a) for a in raw_input().split()] for b in range(T)]

for x in clf.predict(poly.fit_transform(X)):
    print x
