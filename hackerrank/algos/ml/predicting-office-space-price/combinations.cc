//Victor Guerra <vguerra@gmail.com>
//20141127

//http://stackoverflow.com/questions/9430568/generating-combinations-in-c

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, r;
    std::cin >> n;
    std::cin >> r;

    std::vector<bool> v(n);
    std::fill(v.begin() + n - r, v.end(), true);

    do {
        for (int i = 0; i < n; ++i) {
          std::cout << v[i] << " ";
        }
        std::cout << "\n";
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                std::cout << (i+1) << " ";
            }
        }
        std::cout << "\n\n";
    } while (std::next_permutation(v.begin(), v.end()));
    return 0;
}
