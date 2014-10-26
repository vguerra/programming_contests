// Victor Guerra <vguerra@gmail.com>
// 2013-03-10
//
// https://www.hackerrank.com/challenges/angry-children
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  unsigned long N, T;
  cin >> N >> T;
  
  vector<unsigned long> pkgs(N);
 
  for (int i = 0; i < N; ++i) {
    cin >> pkgs[i];
  }

  sort(pkgs.begin(), pkgs.end());

  unsigned long min_unfairness = ULONG_MAX;
  for (int i = 0; i + T <= N; ++i) {
    
    unsigned long curr_unfairness = pkgs[i + T - 1] - pkgs[i];
    if ( curr_unfairness < min_unfairness ) {
      min_unfairness = curr_unfairness;
    }
  }
  cout << min_unfairness << "\n";
  return EXIT_SUCCESS;
}
