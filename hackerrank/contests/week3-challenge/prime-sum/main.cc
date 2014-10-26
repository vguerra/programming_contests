//Victor Guerra <vguerra@gmail.com>
//2014-05-21

//Hacker Rank - Prime Sum 
//https://www.hackerrank.com/contests/w3/challenges/prime-sum

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool isPrime(uint64_t n) {
  if (n <= 1 ) return false; 
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (uint64_t i = 3; i < sqrt(n); i+= 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void writeAsSumOfPrimes(uint64_t n, uint64_t goal, uint64_t &count) {
  if (goal == count) return;
  if (isPrime(n - 2)) {
    count += 1;
    writeAsSumOfPrimes(n - 2, goal, count);
  } else {
    for (uint64_t i = 3; i <= n/2 ; i += 2) {
      if (isPrime(i) && isPrime(n - i)) {
        count += 1;
        writeAsSumOfPrimes(n - i, goal, count);
        writeAsSumOfPrimes(i, goal, count);
        break;
      }
    }
  }
}

int main () {
  unsigned T; 
  uint64_t N,K; 

  cin >> T; 

  while (T--) {
    cin >> N >> K;
    if (K == 1) {
      printf("%s\n", (isPrime(N) ? "Yes" : "No"));
    } else {
      uint64_t primes = 1;  
      writeAsSumOfPrimes(N, K, primes);
      printf("%s\n", (K == primes ? "Yes" : "No"));
    }
  }
  return EXIT_SUCCESS;
}
