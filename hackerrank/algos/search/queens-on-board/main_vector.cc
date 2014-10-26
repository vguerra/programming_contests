// Victor Guerra <vguerra@gmail.com>
// 2014-03-27
// https://www.hackerrank.com/challenges/queens-on-board
//

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

//#include <google/profiler.h>


#define MAX_N 50
#define MAX_M 5

using namespace std;

char board[MAX_N*MAX_M];

uint64_t combinations;

void printFree(vector<int> queens, int N, int M) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << (std::find(queens.begin(), queens.end(), i*M + j) != queens.end() ? " * " : " _ ");
    }
    cout << "\n";
  }
}

bool validSquare(vector<int> queens, int square, int N, int M) {
  int row = square / M;
  int column = square % M; 
  
  // we traverse over the queens we placed already 
  // on the board and see if there is a posible attack.
  //
  for (auto queen : queens) {
    int queenRow =  queen / M;
    int queenColumn = queen % M;

    // check for row attack
    if (queenRow == row) {
      int start  = std::min(square, queen) + 1;
      int end = std::max(square, queen);
      while (start < end) {
        if (board[start] == '#') break;
        ++start;
      }
      if (start == end) return false;
    } else if (queenColumn == column) {
      int start = std::min(square, queen) + M;
      int end = std::max(square, queen);
      while (start < end) {
        if (board[start] == '#') break;
        start += M;
      }
      if (start == end) return false;
    } else if ( (row - queenRow) == (queenColumn - column) ) {
      int start = std::min(square, queen) + M - 1;
      int end = std::max(square, queen);
      while (start < end) {
        if (board[start] == '#') break;
        start += M - 1;
      }
      if (start  == end) return false;
    } else if ( (row - queenRow) == (column - queenColumn) ) {
      int start = std::min(square, queen) + M + 1;
      int end = std::max(square, queen);
      while (start < end) {
        if (board[start] == '#') break;
        start += M + 1;
      }
      if (start == end) return false;
    }
  }
  return true;
}

void tryMove(vector<int> queens, int square, int N, int M, uint64_t& combinations) 
{
  int i = square / M;
  int j = square % M;
  //cout << "tryMove (" << i << ", " << j <<")\n";
  if (board[square] == '#') return; 
  if (validSquare(queens, square, N, M)) {
    ++combinations;
    queens.push_back(square);
    //printFree(queens, N, M);
    for (int s = square + 1; s < M*N; ++s) {
      tryMove(queens, s, N, M, combinations);
    }
  }
}

int main() {
  int T, N, M;
  cin >> T;

  //ProfilerStart("/tmp/profiler.log");
  while (T--) {
    cin >> N >> M;

    combinations = 0;

    for (int i = 0; i < N*M; ++i) {
      cin >> board[i];
    }
    vector<int> queens;
    //tryMove(queens, 0, N, M, combinations);
    for (int i = 0; i < M*N; ++i) {
      tryMove(queens, i, N, M, combinations);
    }
    //
    //
    //testing row blocking
    //queens.push_back(3);
    //cout << validSquare(queens, 5, N, M) << "\n";
    cout << combinations % 1000000007 << "\n";
  }
  //ProfilerStop();
}
