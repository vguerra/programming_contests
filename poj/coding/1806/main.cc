//Victor Guerra <vguerra@gmail.com>
//2014-05-04

//http://poj.org/problem?id=1806
//POJ - 1806

#include <iostream>
#include <algorithm>

using namespace std;

void printSlice(int *grid[], int size, int slice) {
  cout << "slice #" << slice << ":\n";
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (grid[i][j] != -1) {
        cout << grid[i][j];
      } else {
        cout << ".";
      }
    }
    cout << "\n";
  }
}


void propagate(int *grid[], bool visited[], int size, int units, int i, int j) {
  if (i < 0 || i >= size || j < 0 || j >= size || visited[i*size + j]) return;
  if (grid[i][j] == -1) {
    grid[i][j] = units; 
    visited[i*size + j] = true;
  } else {
    if (!visited[i*size + j]) {
      --grid[i][j];
      visited[i*size + j] = true;
    }
    propagate(grid, visited, size, units, i + 1, j);
    propagate(grid, visited, size, units, i, j + 1);
    propagate(grid, visited, size, units, i - 1, j);
    propagate(grid, visited, size, units, i, j - 1);
  }
}

void contract(int *grid[], bool visited[], int size, int units, int i, int j) {
  if (i < 0 || i >= size || j < 0 || j >= size || visited[i*size + j]) return;
  if (grid[i][j] == units) {
    grid[i][j] = -1; 
    visited[i*size + j] = true;
  } else {
    if (!visited[i*size + j]) {
      ++grid[i][j];
      visited[i*size + j] = true;
    }
    contract(grid, visited, size, units, i + 1, j);
    contract(grid, visited, size, units, i, j + 1);
    contract(grid, visited, size, units, i - 1, j);
    contract(grid, visited, size, units, i, j - 1);
  }
}


int main() {
  int lines;
  cin >> lines;
  for (int s = 1; s <= lines; ++s) {
    int units;
    cin >> units;
    int grid_size = 2*units + 1;
    int **grid = new int *[grid_size];
    bool *visited = new bool[grid_size * grid_size];
    for (int i = 0; i < grid_size; ++i) {
      grid[i] = new int[grid_size];
      std::fill(grid[i], grid[i] + grid_size, -1);
    }
    cout << "Scenario #" << s << ":\n";
    for (int st = 1; st <= units + 1; ++st) {
      std::fill(visited, visited + grid_size*grid_size, false);
      propagate(grid, visited, grid_size, units, grid_size/2, grid_size/2);
      printSlice(grid, grid_size, st);
    }
    for (int st = units + 2; st <= grid_size; ++st) {
      std::fill(visited, visited + grid_size*grid_size, false);
      contract(grid, visited, grid_size, units, grid_size/2, grid_size/2);
      printSlice(grid, grid_size, st);
    }

    for (int i = 0; i < 2*units + 1; ++i) {
      delete[] grid[i];
    }
    delete[] grid;
    cout << "\n";  
  } 
  return 0;
}
