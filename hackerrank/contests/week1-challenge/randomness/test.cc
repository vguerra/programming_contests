//Victor Guerra <vguerra@gmail.com>
//2014-04-25

//Testing the randomness problem at 
//https://www.hackerrank.com/contests/w1/submissions/code/1466709

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// we want to have letters between a-z
#define LOW_CHAR 97
#define HIGH_CHAR 122

#define TEST_NAME "test.auto"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "usage: " << argv[0] << " N Q\n";
  }

  unsigned N = atoi(argv[1]);
  unsigned Q = atoi(argv[2]);

  ofstream file (TEST_NAME, std::ofstream::trunc);
 
  if (file.is_open()) {
    file << N << " " << Q << "\n"; 
    
    // randome generated string of length N
    srand(time(NULL));
    
    for (unsigned i = 0; i < N; ++i) {
      file << char(rand() % (HIGH_CHAR - LOW_CHAR) + LOW_CHAR); 
    }
    file << "\n";
    for (unsigned i = 0; i < Q; ++i) {
      file << (rand() % N + 1) << " " << char(rand() % (HIGH_CHAR - LOW_CHAR) + LOW_CHAR) << "\n";
    }
    file << "\n";
    file.close();
  }
  return 0;
}
