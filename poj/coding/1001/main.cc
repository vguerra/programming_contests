//Victor Guerra <vguerra@gmail.com>
//2014-05-05

//http://poj.org/problem?id=1001
//POJ - 1001

#include <iostream>
#include <string>
#include <cstddef>

#define IVAL(x) ((x) - '0')
#define CVAL(x) ((x) + '0')

using namespace std;

string normalizeNum(string a) {
  size_t period_pos = a.find_first_of(".");
  size_t non_zero = a.find_first_not_of("0");
  if (non_zero != 0) {
    a.erase(0, non_zero);
  }
  // trim zeros - back 
  non_zero = a.find_last_not_of("0");
  if (period_pos != string::npos && non_zero != a.length() - 1) {
    a.erase(non_zero + 1);
  }
  
  // is the result an integer? 1.000 ^ 2 e.g.
  if (*(a.end() - 1) == '.') {
    a.erase(a.end() - 1);
  }
  if (a == "") {
    a = "0";
  }
  return a;
}

string mult(string a,string b) {
  string result;
  size_t a_period_pos = a.find_first_of('.');
  size_t b_period_pos = b.find_first_of('.');
  unsigned decimal_count = 0; 
  unsigned r_len = a.length() + b.length();
  if (a_period_pos != string::npos) {
    decimal_count += a.length() - a_period_pos - 1; 
    --r_len;
    a.erase(a.begin() + a_period_pos);
  }
  if (b_period_pos != string::npos) {
    decimal_count += b.length() - b_period_pos - 1; 
    --r_len;
    b.erase(b.begin() + b_period_pos);
  }
  result.resize(r_len, '0'); 
  unsigned carry = 0;
  for (int j = b.length() - 1; j >= 0; --j) {
    for (int i = a.length() - 1; i >= 0; --i) {
      unsigned r = IVAL(a[i])*IVAL(b[j]) + carry +  IVAL(result[i + j + 1]);
      unsigned d = r%10;
      carry = r/10;
      result.replace(i + j + 1, 1, 1, CVAL(d));
    }
    unsigned r = IVAL(result[j]) + carry;
    unsigned d = r%10;
    carry = r/10;
    result.replace(j, 1, 1, CVAL(d));
  }
  if (decimal_count) {
    result.insert(result.length() - decimal_count, 1, '.');
  }
  return normalizeNum(result);
} 

int main() {
  string num; 
  int n; 
  
  while ((cin >> num >> n)) {
    if (n == 0) {
      cout << "1\n";
    } else if ( n == 1) {
      cout << normalizeNum(num) << "\n";
    } else {
      string tmp(num);
      while (n-- - 1) {
       tmp = mult(num, tmp); 
      }
      cout << tmp << "\n";
    }
  }
  return 0;
}
