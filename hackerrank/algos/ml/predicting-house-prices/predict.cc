// Victor Guerra <vguerra@gmail.com>
// 20141119

// https://www.hackerrank.com/challenges/predicting-house-prices

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include <dlib/matrix.h>

int main() {
  unsigned F, N, T;
  std::cin >> F >> N;

  dlib::matrix<double> train_data(N, F + 1);
  dlib::matrix<double> features(N, F + 1);
  dlib::matrix<double> featuresT(F + 1, N);
  dlib::matrix<double, 0, 1> prices(N);
  dlib::matrix<double, 0, 1> parameters(F + 1);
  
  std::cin >> train_data;

  prices = dlib::colm(train_data, F);

  dlib::set_colm(features, 0) = 1.0;

  dlib::set_subm(features, dlib::range(0, N - 1), dlib::range(1, F - 1)) =
      dlib::subm(train_data, dlib::rectangle(0, 0, F - 1, N - 1));

  featuresT = dlib::trans(features);

  std::cin >> T;
  dlib::matrix<double> features_test(T, F + 1);
  dlib::matrix<double> test_data(T, F);
  std::cin >> test_data;

  dlib::set_colm(features_test, 0) = 1.0;
  dlib::set_subm(features_test, dlib::range(0, T - 1), dlib::range(1, F - 1)) =
      test_data;
  //std::cout << features_test;
  parameters = dlib::inv(featuresT * features) * featuresT * prices;

  //std::cout << parameters;
  std::cout << features_test*parameters;

  return 0;
}
