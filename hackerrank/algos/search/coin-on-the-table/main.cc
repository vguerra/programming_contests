// Victor Guerra <vguerra@gmail.com>
// 2014-03-26
// https://www.hackerrank.com/challenges/coin-on-the-table
//

#include <iostream>
#include <utility>

using namespace std;

#define MAX_ROWS_COLS 50

char table[MAX_ROWS_COLS][MAX_ROWS_COLS];
int counts[MAX_ROWS_COLS][MAX_ROWS_COLS];

int n, m, k;

void DFS(int i, int j, int time, int switches) {
  if (i >= 0 && i < n && j >= 0 && j < m && time <= k &&
      switches < counts[i][j]) {

    counts[i][j] = switches;
    int c = table[i][j];

    DFS(i - 1, j, time + 1, switches + (c != 'U'));
    DFS(i + 1, j, time + 1, switches + (c != 'D'));
    DFS(i, j - 1, time + 1, switches + (c != 'L'));
    DFS(i, j + 1, time + 1, switches + (c != 'R'));
  }
}

int main() {

  int start_i = 0;
  int start_j = 0;
  int goal_i, goal_j;
  cin >> n >> m >> k;

  int infinite = 2 * MAX_ROWS_COLS * MAX_ROWS_COLS;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> table[i][j];
      counts[i][j] = infinite;
      if (table[i][j] == '*') {
        goal_i = i;
        goal_j = j;
      }
    }
  }

  DFS(start_i, start_j, 0, 0);
  cout << ((counts[goal_i][goal_j] == infinite) ? -1 : counts[goal_i][goal_j])
       << "\n";

  return 0;
}
