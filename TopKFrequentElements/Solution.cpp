#include <vector>
#include <cstring>
#include <iostream>
#include <map>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::map<int, int> freqs;

    for (auto i : nums) {
      freqs[i]++;
    }
    
    std::multimap<int, int> reversed;
    for (auto i : freqs) {
      reversed.insert({i.second, i.first});
    }

    std::vector<int> res;
    auto j = 0;
    for (auto it = reversed.rbegin(); it != reversed.rend() && j < k; ++it, j++) {
      res.push_back(it->second);
    }
    
    return res;

  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;

  std::vector<int> res = s.topKFrequent(nums, k);
  for (auto it = res.begin(); it != res.end(); ++it) {
    std::cout << *it << "\n";
  }
  
  return 0;
}
