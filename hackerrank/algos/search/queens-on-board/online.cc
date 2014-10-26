/* You have an N * M chessboard on which some squares are blocked out. In how many ways can you place one or more queens on the board such that no two queens attack each other? Two queens attack each other if one can reach the other by moving horizontally, vertically or diagonally without passing over any blocked square. At most one queen can be placed on a square. A queen cannot be placed on a blocked square. */


/* Each test case contains integers N and M on the first line.
 The following N lines contain M characters each representing the board.
 A ‘#’ represents a blocked square and a ‘.’ represents an unblocked square.*/

#include <iostream>
#include <vector>

using namespace std;

const char emptry = '.';
const char blocked = '#';

class chessGame {
public:
    chessGame();
    ~chessGame();
    void countWays();
private:
    bool isValidPos(vector<int> &, int);
    bool isAttackInRow(vector<int> &, int);
    bool isAttackInColumn(vector<int> &, int);
    bool isAttackInDiagonal(vector<int> &, int);
    void countRec(vector<int>, int, int &);
private:
    int N, M;
    char * board;
};

chessGame::chessGame() {
    cin >> N >> M;
    board = new char[N*M];
    for (int i = 0; i < N*M; ++i) {
        cin >> board[i];
    }
}

chessGame::~chessGame() {
    delete[] board;
}

void chessGame::countWays() {
    vector<int> queenPos;
    int count = 0;
    for (int i = 0; i < M*N; ++i) {
        countRec(queenPos, i, count);
    }
    cout << count % 1000000007 << endl;
}

void chessGame::countRec(vector<int> queenPos, int testPos, int & count) {
    if (board[testPos] == blocked) {
        return;
    }
    if (isValidPos(queenPos, testPos)) {
        ++count;
        queenPos.push_back(testPos);
        for (int i = testPos+1; i < M*N; ++i) {
            countRec(queenPos, i, count);
        }
    }
}

bool chessGame::isValidPos(vector<int> & queenPos, int testPos) {
    return !isAttackInRow(queenPos, testPos) && !isAttackInColumn(queenPos, testPos) && !isAttackInDiagonal(queenPos, testPos);
}

bool chessGame::isAttackInRow(vector<int> & queenPos, int testPos) {
    int testRow = testPos / M;
    for (int i = 0; i < queenPos.size(); ++i) {
        int queenRow = queenPos[i] / M;
        if (testRow == queenRow) {
            int j;
            for (j = min(queenPos[i], testPos)+1; j < max(queenPos[i], testPos); ++j) {
                if (board[j] == blocked) {
                    break;
                }
            }
            if (j == max(queenPos[i], testPos)) {
                return true;
            }
        }
    }
    return false;
}

bool chessGame::isAttackInColumn(vector<int> & queenPos, int testPos) {
    int testColumn = testPos % M;
    for (int i = 0; i < queenPos.size(); ++i) {
        int queenColumn = queenPos[i] % M;
        if (testColumn == queenColumn) {
            int j;
            for (j = min(queenPos[i], testPos)+M; j < max(queenPos[i], testPos); j += M) {
                if (board[j] == blocked) {
                    break;
                }
            }
            if (j == max(queenPos[i], testPos)) {
                return true;
            }
        }
    }
    return false;
}

bool chessGame::isAttackInDiagonal(vector<int> & queenPos, int testPos) {
    int testRow = testPos / M;
    int testColumn = testPos % M;
    for (int i = 0; i < queenPos.size(); ++i) {
        int queenRow = queenPos[i] / M;
        int queenColumn = queenPos[i] % M;
        if (testRow - queenRow == testColumn - queenColumn) {
            int j;
            for (j = min(queenPos[i], testPos)+(M+1); j < max(queenPos[i], testPos); j += M+1) {
                if (board[j] == blocked) {
                    break;
                }
            }
            if (j == max(queenPos[i], testPos)) {
                return true;
            }
        }
        if (testRow - queenRow == queenColumn - testColumn) {
            int j;
            for (j = min(queenPos[i], testPos)+(M-1); j < max(queenPos[i], testPos); j += M-1) {
                if (board[j] == blocked) {
                    break;
                }
            }
            if (j == max(queenPos[i], testPos)) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char ** argv) {
    int numTests;
    cin >> numTests;
    for (int i = 0; i < numTests; ++i) {
        chessGame game1;
        game1.countWays();
    }
    return 0;

}
