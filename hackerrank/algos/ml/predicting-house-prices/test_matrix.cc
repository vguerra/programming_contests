#include <dlib/matrix.h>
#include <algorithm>
#include <iostream>
#include <iterator>

int main() {
  dlib::matrix<double, 2, 2> obj;

  std::copy_n(std::istream_iterator<double>(std::cin), 4, obj.begin());
  
  std::cout << obj;
  return 0;
}
