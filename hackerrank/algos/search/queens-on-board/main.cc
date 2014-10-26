// Victor Guerra <vguerra@gmail.com>
// 2014-03-27
// https://www.hackerrank.com/challenges/queens-on-board
//

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

#define MAX_N 50
#define MAX_M 5

using namespace std;

char board[MAX_N][MAX_M];

// keeping track of what squares are occupied
bool fr[MAX_N][MAX_M];

// keeping tack of bloqued squares.

vector<int> blocked_cols[MAX_M];
vector<int> blocked_rows[MAX_N];
vector<int> blocked_dr[MAX_N + MAX_M - 1];
vector<int> blocked_dl[MAX_N + MAX_M - 1];

uint64_t combinations;

void printFree(int N, int M) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << ((fr[i][j]) ? " _ " : " * ");
    }
    cout << "\n";
  }
}

bool validSquare(vector<int> queens, int row, int column, int N, int M) {
  if (board[row][column] == '#') return false;

  int square = row*M + column;
  for (auto queen : queens) {
    int qRow = queen / M;
    int qCol = queen % M;
 
    bool isOk = false;
    // row attack
    if (row == qRow) {
      for (auto runner : blocked_rows[row]) {
        if (queen < runner && runner < square) {
          isOk = true;
          break;
        }
      }
      if (!isOk) return false;
    } else if (column == qCol) {
      for (auto runner : blocked_cols[column]) {
        if (queen < runner & runner < square) {
          isOk = true;
          break;
        }
      }
      if (!isOk) return false;
    } else if (qRow + qCol == column + row) {
      for (auto runner : blocked_dr[qRow + qCol]) {
        if (queen < runner & runner < square) {
          isOk = true;
          break;
        }
      }
      if (!isOk) return false;
    } else if (qCol - qRow == column - row) {
      for (auto runner : blocked_dl[qRow - qCol + M - 1]) {
        if (queen < runner & runner < square) {
          isOk = true;
          break;
        }
      }
      if (!isOk) return false;
    }
  }
  return true;
}

void tryMove(vector<int> queens, int square, int N, int M, uint64_t& combinations) 
{
  int i = square / M;
  int j = square % M;
  //cout << "tryMove (" << i << ", " << j <<")\n";
  if (validSquare(queens, i, j, N, M)) {
    ++combinations;
    queens.push_back(square);
    //cout << "i: " << i << ", j: " << j << " is valid\n";
    //printFree(N, M);
    for (int s = square + 1; s < M*N; ++s) {
      tryMove(queens, s, N, M, combinations);
    }
  }
}

int main() {
  int T, N, M;
  cin >> T;

  while (T--) {
    cin >> N >> M;

    combinations = 0;

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> board[i][j];
        fr[i][j] = true;
        if (board[i][j] == '#') {
          fr[i][j] = false;
          int square = i*M + j;
          blocked_cols[j].push_back(square);
          blocked_rows[i].push_back(square);
          blocked_dr[i + j].push_back(square);
          blocked_dl[i - j + M - 1].push_back(square);
        }
      }
    }
    //for (int i = 0 ; i < N ; ++i) {
      //for (auto pos : blocked_rows[i]) {
        //cout << pos << " ";
      //}
      //cout << "\n";
    //}
    vector<int> queens;
    //tryMove(queens, 0, N, M, combinations);
    
    // testing row conflict
    //cout << "testing row conflicts\n";
    //queens.push_back(10);
    //cout << "is it valid?: " << validSquare(queens, 2, 4, N, M) << "\n";
    //cout << "is it valid?: " << validSquare(queens, 2, 1, N, M) << "\n";
    
    //cout << "testing column conflicts\n";
    //queens.clear();
    //queens.push_back(2);
    //cout << "is it valid?: " << validSquare(queens, 4, 2, N, M) << "\n";
    //cout << "is it valid?: " << validSquare(queens, 1, 2, N, M) << "\n";

    //cout << "testing right diagonal conflicts\n";
    //queens.clear();
    //queens.push_back(4);
    //cout << "is it valid?: " << validSquare(queens, 4, 0, N, M) << "\n";
    //cout << "is it valid?: " << validSquare(queens, 1, 3, N, M) << "\n";

    //cout << "testing left diagonal conflicts\n";
    //queens.clear();
    //queens.push_back(0);
    //cout << "is it valid?: " << validSquare(queens, 4, 4, N, M) << "\n";
    //cout << "is it valid?: " << validSquare(queens, 1, 1, N, M) << "\n";



    for (int i = 0; i < M*N; ++i) {
      tryMove(queens, i, N, M, combinations);
    }
    cout << combinations % 1000000007 << "\n";
  }
}
