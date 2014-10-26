// Victor Guerra <vguerra@gmail.com>
// 2014-05-02

// http://poj.org/problem?id=1007
// POJ - 1007

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool compare(const pair<unsigned, string>& p1, const pair<unsigned, string>& p2) {
  return p1.first < p2.first;
}

unsigned countInversions(char *seq, int size) { 
  if (size == 1) {
    return 0;
  }
  int mid = size/2;
  int left_size = mid; 
  int right_size = size - mid;

  unsigned count = 0; 
  char *left = new char[left_size + 1];
  char *right = new char[right_size + 1];
  for (int i = 0, k = 0 ; i < left_size; ++i, ++k) {
    left[k] = seq[i];
  }
  left[left_size] = '\0';
  for (int i = mid, k = 0; k < right_size; ++i, ++k) {
    right[k] = seq[i];
  }
  right[right_size] = '\0';

  count += countInversions(left, left_size);
  count += countInversions(right, right_size);
 
  int i = 0; 
  int j = 0;
  for (int k = 0; k < size; ++k) {
    if (i >= left_size) {
      seq[k] = right[j++];
    } else if (j >= right_size) {
      seq[k] = left[i++];
    } else if (right[j] < left[i]) {
      seq[k] = right[j++];
      count += left_size - i;
    } else {
      seq[k] = left[i++];
    }
  }

  
  delete[] left;
  delete[] right;
  
  return count; 
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<unsigned, string>> inversions;
  while (m--) {
    string seq;
    cin >> seq;
    char *copy = new char[seq.length() + 1];
    strcpy(copy, seq.c_str());
    inversions.push_back(make_pair(countInversions(copy, n), seq));
    delete[] copy;
  }
  
  sort(inversions.begin(), inversions.end(), compare);
  for (unsigned i = 0; i < inversions.size(); ++i) {
    cout << inversions[i].second << "\n";
  }

  return 0;
}
