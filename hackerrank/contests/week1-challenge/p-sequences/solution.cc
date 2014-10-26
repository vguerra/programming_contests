
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 1000 + 5
#define max_sqrt_k 32000
#define mod 1000000007

int dp[2][max_sqrt_k][2], n, k, sqrt_k, i, j, t, ret, pref, sum0, sum1, count_lr[max_sqrt_k], le, ri, l, p;

void upd (int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

int main (int argc, char * const argv[]) {
  scanf("%d %d", &n, &k);
  while (sqrt_k * sqrt_k < k) ++sqrt_k;
  for(i = 1; i <= sqrt_k; i++) dp[1][i][0] = 1;
  for(i = 1; i < sqrt_k; i++) {
    le = k / (i + 1) + 1;
    ri = k / i;
    if (ri <= sqrt_k) continue;
    le = max(le, sqrt_k + 1);
    count_lr[i] = ri - le + 1;
  }
  for(i = 1; i < sqrt_k; i++) dp[1][i][1] = count_lr[i];
  l = 1;
  for(i = 2; i <= n; i++) {
    p = l;
    l ^= 1;
    sum0 = sum1 = 0;
    for(j = 1; j <= sqrt_k; j++) {
      upd(sum0, dp[p][j][0]);
      upd(sum1, dp[p][j][1]);
    }
    t = sqrt_k;
    for(j = 1; j <= sqrt_k; j++) {
      while (j * t > k) upd(sum0, mod - dp[p][t--][0]);
      dp[l][j][0] = sum1 + sum0;
      if (dp[l][j][0] >= mod) dp[l][j][0] -= mod;
      upd(sum1, mod - dp[p][j][1]);
    }
    pref = 0;
    for(j = 1; j < sqrt_k; j++) {
      upd(pref, dp[p][j][0]);
      dp[l][j][1] = (count_lr[j] * 1LL * pref) % mod;
    }
  }
  for(j = 1; j <= sqrt_k; j++) {
    upd(ret, dp[l][j][0]);
    upd(ret, dp[l][j][1]);
  }
  printf("%d\n", ret);
    return 0;
}
