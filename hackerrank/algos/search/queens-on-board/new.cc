// Victor Guerra <vguerra@gmail.com>
// 2014-03-27
// https://www.hackerrank.com/challenges/queens-on-board
//

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <set>

#define MAX_N 50
#define MAX_M 5

using namespace std;

bool fr[MAX_N * MAX_M];
int blockedCount[MAX_N * MAX_M];

class CellObject {
  public:
  CellObject(int square, int N, int M) : _square(square), _N(N), _M(M), _blocked_ahead(0) {}
  ~CellObject();
  void initConflictZone(int blocked_ahead);
  void blockSquare(int square);
  void printConflictZone();
  bool makesConflict(int square);
  uint64_t freeCells();
  private:
  int _square;
  int _N;
  int _M;
  int _blocked_ahead;
  set<int> _conf[MAX_M];
};


void CellObject::initConflictZone(int blocked_ahead) {
  int row = _square / _M;
  int col = _square % _M;
   

  // conflict squares along the row
  for (int c = col + 1, r = _square + 1; c < _M && fr[r]; ++c, ++r) {
    _conf[c].insert(r);
  }

  // conflic squares along the column
  for (int r = _square + _M; r < _N*_M && fr[r]; r += _M) {
    _conf[col].insert(r);
  } 

  // conflict along the right diagonal
  //int diag = row + col;
  //int start = (diag > (_M - 1) && _M > 1 ? ((diag % (_M-1)) +1)*_M - 1: diag);
  //int srow = start / _M;
  //int scol = start % _M;
  int srow = row + 1;
  int scol = col - 1;
  while (srow < _N && scol >= 0 && fr[srow*_M + scol]) {
    _conf[scol].insert(srow*_M + scol);
    --scol;
    ++srow;
  }

  // conflict along the left diagonal
  //diag = row - col + _M - 1;
  //start = (diag > (_M - 1)) && _M > 1 ? ( (diag % (_M-1)) *_M ) : _M - 1 - diag;
  //srow = start / _M;
  //scol = start % _M;
  srow = row + 1;
  scol = col + 1;
  while (srow < _N && scol < _M && fr[srow*_M + scol]) {
    _conf[scol].insert(srow*_M + scol);
    ++scol;
    ++srow;
  }

  // calculating blocked ahead
  _blocked_ahead = blocked_ahead;
}

void CellObject::printConflictZone() {
  for (int i = 0; i < _M; ++i) {
    cout << "Col " << i << "(" << _conf[i].size() << ") : ";
    for (auto square : _conf[i]) {
      cout << square << ", ";
    }
    cout << "\n";
  }
  cout << "blocked ahead: " << _blocked_ahead << "\n";
}

void CellObject::blockSquare(int square) {
  

}

CellObject::~CellObject() {
  //cout << "destructor for sqaure: " << _square << "\n";
}

bool CellObject::makesConflict(int square) {
  for (int col = 0; col < _M; ++col) {
    if (_conf[col].find(square) != _conf[col].end()) {
      return true; 
    }
  }
  return false;
}

uint64_t CellObject::freeCells() {
  uint64_t conflict_count = 0;
  for (int i = 0; i < _M; ++i) {
    conflict_count += _conf[i].size();
  }
  return _N * _M - _square - conflict_count - _blocked_ahead;
}

uint64_t combinations;
CellObject* cells[MAX_N*MAX_M];

// void printFree(int N, int M) {
// for (int i = 0; i < N; ++i) {
// for (int j = 0; j < M; ++j) {
// cout << ((fr[i][j]) ? " _ " : " * ");
//}
// cout << "\n";
//}
//}

bool validSquare(vector<int> queens, int square) {
  if (cells[square] == nullptr) return false;

  for (auto queen : queens) {
    if (cells[queen]->makesConflict(square)) {
      return false;
    }
  }
  return true;
}

void tryMove(vector<int> queens, int square, int N, int M,
             uint64_t& combinations) {
  if (!fr[square]) return; 
  // cout << "tryMove (" << i << ", " << j <<")\n";
  if (validSquare(queens, square)) {
    ++combinations;
    cout << "valid so far:\n";
    for (auto queen : queens) {
      cout << queen << ", ";
    }
    cout << square << "\n";
    queens.push_back(square);
    // cout << "i: " << i << ", j: " << j << " is valid\n";
    // printFree(N, M);
    for (int s = square + 1; s < M * N; ++s) {
      tryMove(queens, s, N, M, combinations);
    }
  }
}

int main() {
  int T, N, M, blockedTotal;
  cin >> T;

  while (T--) {
    cin >> N >> M;

    combinations = 0;
    blockedTotal = 0;
    std::fill(fr, fr + N*M, true);
    std::fill(blockedCount, blockedCount + N*M, 0);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        char c;
        cin >> c;
        int square = i*M + j;
        if (c == '#') {
          ++blockedTotal;
          cells[square] = nullptr;
          fr[square] = false;
        } else {
          blockedCount[square] = blockedTotal;
          cells[square] = new CellObject(square, N, M);
        }
      }
    }

    for (int i = 0; i < N*M; ++i) {
      if (cells[i] != nullptr) {
        cells[i]->initConflictZone(blockedTotal - blockedCount[i]);
        cout << "Conflict zone for " << i << "\n";
        cells[i]->printConflictZone();
      }
    }
  
    //cout << "done initializing\n";
    //cells[2]->printConflictZone();
    //cells[5]->printConflictZone();
    // for (int i = 0 ; i < N ; ++i) {
    // for (auto pos : blocked_rows[i]) {
    // cout << pos << " ";
    //}
    // cout << "\n";
    //}
    vector<int> queens;
    //tryMove(queens, 0, N, M, combinations);

    // testing row conflict
    // cout << "testing row conflicts\n";
    // queens.push_back(10);
    // cout << "is it valid?: " << validSquare(queens, 2, 4, N, M) << "\n";
    // cout << "is it valid?: " << validSquare(queens, 2, 1, N, M) << "\n";

    // cout << "testing column conflicts\n";
    // queens.clear();
    // queens.push_back(2);
    // cout << "is it valid?: " << validSquare(queens, 4, 2, N, M) << "\n";
    // cout << "is it valid?: " << validSquare(queens, 1, 2, N, M) << "\n";

    // cout << "testing right diagonal conflicts\n";
    // queens.clear();
    // queens.push_back(4);
    // cout << "is it valid?: " << validSquare(queens, 4, 0, N, M) << "\n";
    // cout << "is it valid?: " << validSquare(queens, 1, 3, N, M) << "\n";

    // cout << "testing left diagonal conflicts\n";
    // queens.clear();
    // queens.push_back(0);
    // cout << "is it valid?: " << validSquare(queens, 4, 4, N, M) << "\n";
    // cout << "is it valid?: " << validSquare(queens, 1, 1, N, M) << "\n";

    uint64_t combis = 0;
    for (int i = 0; i < M * N; ++i) {
      cout << "working with " << i << "\n";
      tryMove(queens, i, N, M, combis);
      if (cells[i] != nullptr)
        combinations += cells[i]->freeCells();
    }

    for (int i = 0; i < N * M; ++i) {
      delete cells[i];
    }
    
    cout << combis % 1000000007 << "\n";
    cout << combinations % 1000000007 << "\n";
  }
}
