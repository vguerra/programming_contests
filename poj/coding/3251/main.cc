//Victor Guerra <vguerra@gmail.com>
//2014-05-10

//http://poj.org/problem?id=3251
//POJ - 3251

#define FOR(X,A,Z) for(int X = A; X < Z; ++X)
#define VAL(P) grid[P.first][P.second]
#define AS(P) (P.first < N && P.second < N)

#include <iostream>
#include <utility> 
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> cell;

int main () {
  int N; 
  cin >> N; 
  char **grid = new char*[N];
  int max_grid = 0;
  vector<cell> Johns;

  FOR(i, 0, N) {
   grid[i] = new char[N]; 
  }

  FOR(i, 0, N) {
    FOR(j, 0, N) {
      cin >> grid[i][j];
      if (grid[i][j] == 'J') {
        Johns.push_back(make_pair(i, j));
      }
    }
  }
  
  for (vector<cell>::iterator a = Johns.begin(); a != Johns.end() - 1; ++a) {
    for (vector<cell>::iterator b = a + 1; b != Johns.end(); ++b) {
      cell c1 = *a; 
      cell c2 = *b; 
      if (c1.first == c2.first || c1.second == c2.second) continue;
      //cout << "working with " << c1.first << ", " << c1.second << "\n";
      //cout << "working with " << c2.first << ", " << c2.second << "\n";
      
      int diff_i = c2.first - c1.first;
      int diff_j = c2.second - c1.second;
     
      if (abs(diff_i) != abs(diff_j))  continue;
      //cout << "this have an area of: " << diff_i*diff_j << "\n";
     
      cell c; 
      cell d;
      
      int area; 
      
      c = make_pair(c1.first, c2.second);
      d = make_pair(c2.first, c1.second);
      area = diff_i*diff_j;

      if (area < 0) area *= -1;

      //cout << "c: " << c.first << ", " << c.second << "\n";
      //cout << "d: " << d.first << ", " << d.second << "\n";
      //cout << "with area: " << area << "\n";
      if (AS(c) && AS(d) && (int(VAL(c) + VAL(d)) == int('J' + '*') || int(VAL(c) + VAL(d)) == int('J' + 'J'))) {
        //cout << "we are good\n";
        max_grid = max(max_grid, area);
        continue;
      }

      //cout << "c: " << c.first << ", " << c.second << "\n";
      //cout << "d: " << d.first << ", " << d.second << "\n";
      c = make_pair(c2.first, c1.second - diff_j);
      d = make_pair(c2.first + diff_i ,c1.second);
    
      if (AS(c) && AS(d) && (int(VAL(c) + VAL(d)) == int('J' + '*') || int(VAL(c) + VAL(d)) == int('J' + 'J'))) {
        //cout << "we are good rombo\n";
        max_grid = max(max_grid, area);
      }
    }
  }
  cout << max_grid << "\n"; 
  return 0;
}
