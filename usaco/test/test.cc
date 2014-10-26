/*
ID: vguerra1
PROG: test
LANG: C++11
*/
#include <fstream>
using namespace std;
int main() {
  std::ofstream fout ("test.out");
  std::ifstream fin ("test.in");
  int a, b;
  fin >> a >> b;
  fout << a + b << endl;
  fout.close();
  fin.close();
  return 0;
}
