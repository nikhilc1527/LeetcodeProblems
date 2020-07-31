#include <vector>
#include <limits>

class Solution {
public:
  int minStartValue(std::vector<int>& nums) {
    int sum = 0, min = std::numeric_limits<int>::max();
    for (auto i : nums) {
      sum += i;
      min = std::min(min, sum);
    }
    return std::max(-min + 1, 1);
  }
};
