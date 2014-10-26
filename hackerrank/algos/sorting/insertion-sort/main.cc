// Victor Guerra <vguerra@gmail.com>
// 2014-03-20
//
// https://www.hackerrank.com/challenges/insertion-sort
//

#include <iostream>

using namespace std;

unsigned long merge(unsigned long *ar, unsigned long low, unsigned long mid,
                    unsigned long high) {
  unsigned long shifts = 0;
  unsigned long elements = high - low + 1;
  unsigned long copy[elements];

  for (unsigned long i = 0; i < elements; ++i ) {
    copy[i] = ar[low + i];
  }

  unsigned long lefti = 0; 
  unsigned long righti = mid - low + 1;

  for (unsigned long k = low; k <= high; ++k) {
    if (lefti > (mid - low)) {
      ar[k] = copy[righti++];
    } else if (righti > (high -low)) {
      ar[k] = copy[lefti++];
    } else if (copy[righti] < copy[lefti]) {
      ar[k] = copy[righti++];
      shifts += (mid - low) - lefti + 1;
    } else {
      ar[k] = copy[lefti++];
    } 
  }
  return shifts;
}

unsigned long countShifts(unsigned long *ar, unsigned long low,
                          unsigned long high) {
  if (low >= high) return 0;
  unsigned long mid = (low + high) / 2;
  return countShifts(ar, low, mid) + countShifts(ar, mid + 1, high) +
         merge(ar, low, mid, high);
}

int main() {
  unsigned T;
  cin >> T;
  while (T--) {
    unsigned long N;
    cin >> N;

    unsigned long ar[N];

    for (unsigned long i = 0; i < N; ++i) {
      cin >> ar[i];
    }

    cout << countShifts(ar, 0, N - 1);

//    for (unsigned long i = 0; i < N; ++i) {
//      cout << ar[i] << " ";
//    }
    cout << "\n";

  
  
  }
  return 0;
}
