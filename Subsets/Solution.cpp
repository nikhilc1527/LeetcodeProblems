#include <vector>
#include <cmath>

class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    const int n = nums.size();
    std::vector<std::vector<int>> results;
    for (int i = 0; i < pow(2, n); i++) {
      std::vector<int> v;
      for (int j = 0; j < n; j++) {
	if (i & (1<<j)) {
	  v.push_back(nums[j]);
	}
      }
      results.push_back(move(v));
    }
    return results;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3};
  std::vector<std::vector<int>> res = Solution().subsets(nums);
  
}
