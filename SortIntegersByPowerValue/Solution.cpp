#include <algorithm>
#include <vector>

class Solution {
 public:
  int getKth(int lo, int hi, int k) {
    auto get_power = [](auto i, auto&& get_power) {
      if (i == 1)
        return 0;
      else if (i & 1)
        return get_power(i * 3 + 1, get_power) + 1;
      else
        return get_power(i / 2, get_power) + 1;
    };

    std::vector<std::pair<int, int>> nums(hi - lo + 1);

    for (int i = lo; i <= hi; ++i) {
      nums[i - lo] = {i, get_power(i, get_power)};
    }

    std::sort(nums.begin(), nums.end(),
              [](auto i, auto j) { return i.second < j.second; });

    return nums[k - lo].first;
  }
};
