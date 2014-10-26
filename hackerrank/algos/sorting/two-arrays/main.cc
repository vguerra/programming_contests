// Victor Guerra <vguerra@gmal.com>
// 2014-03-20
//

// https://www.hackerrank.com/challenges/two-arrays

#include <iostream>
#include <algorithm>

using namespace std; 

int main() {
  unsigned T; 
  cin >> T; 

  while (T--) {
    unsigned N;
    unsigned long long K; 

    cin >> N >> K; 

    unsigned long long A[N];
    unsigned long long B[N];

    for (unsigned i = 0; i < N; ++i) {
      cin >> A[i]; 
    }

    for (unsigned i = 0; i < N; ++i) {
      cin >> B[i]; 
    }

    sort(A, A + N);
    sort(B, B + N, greater<unsigned long long>());

    unsigned index = 0; 

    while (index < N && (A[index] + B[index] >= K)) {
      ++index;
    }

    cout << ((index == N) ? "YES" : "NO");
    cout << "\n";
  }

  
  return 0;
}
