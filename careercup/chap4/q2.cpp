#include <cstdlib>
#include <string>
#include <iostream>

void binaryRep(char* double_str) {
  std::string str(double_str);
  std::size_t point_pos = str.find(".");
  std::string integer_str = str.substr(0, point_pos);
  std::string decimal_str = str.substr(point_pos, str.length());
  std::cout << "position is " << point_pos << "\n";
  std::cout << "integer str is " << integer_str << "\n";
  std::cout << "decimal str is " << decimal_str << "\n";

  std::string binary_rep("");
  int integer_part = atoi(integer_str.c_str());

  while (integer_part > 0) {
    int r = integer_part % 2; 
    binary_rep = std::to_string(r) + binary_rep; 
    integer_part >>= 1; 
  }
  binary_rep += ".";

  double decimal_part = atof(decimal_str.c_str());

  while (decimal_part > 0) {
    if (decimal_part == 1) {
      binary_rep += "1";
      break;
    }
    double r = decimal_part * 2;

    if (r >= 1 ) {
      decimal_part = r - 1;
      binary_rep += "1";
    } else {
      binary_rep += "0";
      decimal_part = r; 
    }
  
  }

  std::cout << "the final result is: " << binary_rep << "\n";
}

int main() {
  char str[] = "3.8";
  binaryRep(str);
  return 0;
}

