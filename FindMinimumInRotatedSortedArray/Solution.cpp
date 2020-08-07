#include <vector>
#include <utility>
#include <cmath>
#include <iostream>

class Solution {
public:
  int findMin(std::vector<int> &nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi - 1) {
      int mid = lo + (hi - lo) / 2;
      // mid on left of min
      if (nums[mid] > nums[lo] && nums[mid] > nums[hi]) {
        lo = mid;
      }
      else if (nums[mid] < nums[hi] && nums[mid] < nums[lo]) {
        hi = mid;
      }
      else {
        if (nums[hi] > nums[nums.size() - 1]) {
          lo = hi;
          hi = nums.size() - 1;
        } else {
          hi = lo;
          lo = 0;
        }
      }
    }

    return std::min(nums[hi], nums[lo]);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums =
  { 3,
    4,
    5,
    1,
    2 };

  std::cout << s.findMin(nums) << '\n';

  nums =
  { 4,
    5,
    6,
    7,
    0,
    1,
    2 };

  std::cout << s.findMin(nums) << '\n';

  nums =
    { 0 };

  std::cout << s.findMin(nums) << '\n';

  nums =
  { 1,
    2,
    3 };

  std::cout << s.findMin(nums) << '\n';

  nums =
  { 4,
    5,
    6,
    1 };

  std::cout << s.findMin(nums) << '\n';

  nums =
  { 1,
    2 };

  std::cout << s.findMin(nums) << '\n';

  return 0;
}
