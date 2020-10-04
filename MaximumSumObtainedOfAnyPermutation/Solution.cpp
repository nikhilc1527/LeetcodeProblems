#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

class Solution {
 public:
  int maxSumRangeQuery(std::vector<int>& nums,
                       std::vector<std::vector<int>>& requests) {
    std::sort(nums.begin(), nums.end(), std::greater<int>{});
    std::vector<int> ranges(nums.size());
    for (auto& i : requests) {
      for (int j = i[0]; j <= i[1]; ++j) {
        ranges[j]++;
      }
    }
    std::sort(ranges.begin(), ranges.end(), std::greater<int>{});
    int res = 0, mod = 1e9 + 7;
    for (int i = 0; i < ranges.size(); ++i) {
      res += (int)(((size_t)nums[i]) * ranges[i] % mod);
    }

    return res;
  }
};
