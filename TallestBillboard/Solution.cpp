#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
  int tallestBillboard(std::vector<int>& rods) {
    std::sort(rods.begin(), rods.end());
    int sum = std::accumulate(rods.begin(), rods.end(), 0);
  }
};
