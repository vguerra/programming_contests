#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<std::pair<int,int> > meassures = {{68, 50}, {68, 51}, {68, 49}};
  std::sort(meassures.begin(), meassures.end());

  for (const auto& pair: meassures) {
    std::cout << "H: " << pair.first << " W: " << pair.second << "\n";
  }
  return 0;
}
