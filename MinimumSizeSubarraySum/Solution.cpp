#include <vector>
#include <iostream>

class Solution {
public:
  int minSubArrayLen(int s, std::vector<int>& nums) {
    int sum = 0, minLen = nums.size() + 1;
    int i = 0, j = 0;
    while (j < nums.size()) {
      while (j < nums.size() && sum < s) {
	sum += nums[j];
	j++;
      }
      if (sum >= s) {
	minLen = std::min(minLen, j - i);
      }
      while (i < j && sum >= s) {
	sum -= nums[i];
	i++;
      }
      if (sum < s) {
	minLen = std::min(minLen, j - i + 1);
      }
    }

    return minLen > nums.size() ? 0 : minLen;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> nums = {2, 3, 1, 2, 4, 3};
  int s = 7;
  std::cout << Solution().minSubArrayLen(s, nums) << '\n';
  
  return 0;
}
