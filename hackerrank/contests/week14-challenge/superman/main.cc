// Victor Guerra <vguerra@gmail.com>
// 20150312

// https://www.hackerrank.com/contests/w14/challenges/superman-celebrates-diwali

#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <vector>

using vv = std::vector<std::vector<unsigned>>;

int main() {
  unsigned N, H, I;
  std::cin >> N >> H >> I;

  vv buildings(H, std::vector<unsigned>(N, 0));
  std::vector<unsigned> max_in_floor(H, 0);
  for (unsigned b = 0; b < N; ++b) {
    unsigned persons_in_bulding;
    std::cin >> persons_in_bulding;
    for (unsigned h = 0; h < persons_in_bulding; ++h) {
      unsigned height;
      std::cin >> height;
      ++buildings[height - 1][b];
    }
  }

  vv ppl_saved(N, std::vector<uint32_t>(H, 0));

  // counter initialization for all levels under I
  for (unsigned b = 0; b < N; ++b) {
    unsigned init_h = H - 1;
    unsigned fin_h = init_h - I;
    ppl_saved[b][init_h] = buildings[H - 1][b];
    for (unsigned h = init_h - 1; h > fin_h; --h) {
      ppl_saved[b][h] = ppl_saved[b][h + 1] + buildings[h][b];
    }
  }

  // precompute max
  for (unsigned h = H - I; h < H; ++h) {
    max_in_floor[h] = 0;
    for (unsigned b = 0; b < N; ++b) {
      max_in_floor[h] = std::max(max_in_floor[h], ppl_saved[b][h]);
    }
  }

  for (int h = H - I - 1; h >= 0; --h) {
    for (unsigned b = 0; b < N; ++b) {
      ppl_saved[b][h] =
          buildings[h][b] + std::max(ppl_saved[b][h + 1], max_in_floor[h + I]);
    }

    // calculate for next rounds
    max_in_floor[h] = 0;
    for (unsigned b = 0; b < N; ++b) {
      max_in_floor[h] = std::max(max_in_floor[h], ppl_saved[b][h]);
    }
  }

  std::cout << max_in_floor[0] << "\n";
  return EXIT_SUCCESS;
}
