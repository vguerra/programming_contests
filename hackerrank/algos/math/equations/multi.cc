#include <cstdio>

int multiplicity(int n, int p) {
    int q = n, m = 0;
    if (p > n) return 0;
    if (p > n/2) return 1;
    while (q >= p) {
        q /= p;
        m += q;
    }
    return m;
}

int main() {
  printf("%d %d %d\n", 32327, 2, multiplicity(32327, 4861) );
  return 0;

}
