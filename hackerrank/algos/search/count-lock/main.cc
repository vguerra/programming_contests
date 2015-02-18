//Victor Guerra <vguerra@gmail.com>
//20150209

//https://www.hackerrank.com/challenges/count-luck

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <stack>
#include <utility>

struct cell {
  unsigned X; 
  unsigned Y;
  bool operator==(const cell& x) {
    return (X == x.X && Y == x.Y);
  }
};

using Cell = struct cell;
using sElem = std::pair<Cell, unsigned>;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

#define STEPS 4 

int main() {
  unsigned T; 
  std::cin >> T; 

  while (T--) {
    unsigned N, M, K; 
    Cell initP;
    Cell finalP; 
    std::cin >> N >> M; 
    std::vector<std::vector<bool>> grid(N, std::vector<bool>(M, true));
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
    std::stack<sElem> cellsQ;
    
    std::cin.ignore(1, '\n');
    
    unsigned waves = 0;
    for (unsigned i = 0; i < N; ++i) {
      std::string line; 
      std::getline(std::cin, line);
      for (unsigned j = 0; j < M; ++j) {
        switch (line[j]) {
          case '.':
            break;
          case 'X':
            grid[i][j] = false;
            break;
          case 'M':
            initP.X = i;
            initP.Y = j;
            break;
          case '*':
            finalP.X = i;
            finalP.Y = j;
            break;
        }
      }
    }
    std::cin >> K;

    cellsQ.push(std::make_pair(initP, 0));

    while (!cellsQ.empty()) {
      sElem el = cellsQ.top(); 
      Cell p = el.first;
      unsigned count_so_far = el.second;
      cellsQ.pop();
      if (p == finalP) {waves = count_so_far; break;}
      if (!visited[p.X][p.Y]) {
        visited[p.X][p.Y] = true;
        unsigned countOptions = 0;
        for (unsigned s = 0; s < STEPS; ++s) {
          int nX = p.X + dx[s]; 
          int nY = p.Y + dy[s];
          if (nX >= 0 && nX < (int)N && nY >= 0 && nY < (int)M && !visited[nX][nY] && grid[nX][nY]) {
            ++countOptions;
          }
        }
        if (countOptions > 1) {
          ++count_so_far;
        }
        for (unsigned s = 0; s < STEPS; ++s) {
          int nX = p.X + dx[s]; 
          int nY = p.Y + dy[s];
          if (nX >= 0 && nX < (int)N && nY >= 0 && nY < (int)M && !visited[nX][nY] && grid[nX][nY]) {
            Cell newP = Cell();
            newP.X = nX;
            newP.Y = nY;
            cellsQ.push(std::make_pair(newP, count_so_far));
          }
        }
      } 
    }
    if (waves == K) {
      std::cout << "Impressed";
    } else {
      std::cout << "Oops!";
    }
    std::cout << "\n";
  }
  return EXIT_SUCCESS;
}
