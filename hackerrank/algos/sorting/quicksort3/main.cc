//Victor Guerra <vguerra@gmail.com>
//20150205

//https://www.hackerrank.com/challenges/quicksort3

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>

inline void printV(const std::vector<int>& nums) {
  for (auto const& n : nums) std::cout << n << " ";
  std::cout << "\n";
}

std::size_t partition(std::vector<int>& nums, long int left, long int right) {
  long int runner = left; 
  while (runner < right) {
    if (nums[runner] < nums[right]) {
      std::swap(nums[left], nums[runner]);
      ++left;
    }
    ++runner;
  }
  std::swap(nums[right], nums[left]); 

  return left;
}

void quickSort(std::vector<int>& nums, long int left, long int right) {
  if (left >= right) return;
  std::size_t pivot = partition(nums, left, right);
  printV(nums);
  quickSort(nums, left, pivot - 1);
  quickSort(nums, pivot + 1, right);
}

int main() {
  unsigned n;
  std::cin >> n; 
  std::vector<int> nums(n);
  std::copy_n(std::istream_iterator<int>(std::cin), n, nums.begin());
  
  quickSort(nums, 0, nums.size() - 1);
  return EXIT_SUCCESS;
}
