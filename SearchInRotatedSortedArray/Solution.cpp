#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
  int search(std::vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    int mid = 0, jumpLen = (nums.size() + 1) / 2, size = nums.size();
    bool fin = false, fin2 = false;
    while (!fin) {
      if (nums[mid] == target) return mid;
      else if (target < nums[mid]) {
	mid -= jumpLen;
	if (nums[(mid + size) % size] > nums[mid + jumpLen]) mid += jumpLen;
	else if (mid < 0) mid += size;
      }
      else {
	mid += jumpLen;
	if (nums[mid % size] < nums[mid - jumpLen]) mid -= jumpLen;
	else if (mid >= size) mid -= size;
      }
      jumpLen = static_cast<int>(std::round(jumpLen / 2.0));
      if (jumpLen == 1 && !fin2) fin2 = true;
      else if (jumpLen == 1 && fin2) fin = true;
    }
    if (nums[mid] == target)
      return mid;
    else return -1;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  std::cout << Solution().search(nums, target) << '\n';
  nums = {1, 3, 5};
  target = 5;
  std::cout << Solution().search(nums, target) << '\n';
  nums = {1, 2, 3, 4, 5};
  target = 5;
  std::cout << Solution().search(nums, target) << '\n';
  nums = {5, 1, 2, 3, 4};
  target = 4;
  std::cout << Solution().search(nums, target) << '\n';
  nums = {4, 5, 6, 7, 0, 1, 2};
  target = 3;
  std::cout << Solution().search(nums, target) << '\n';

  return 0;
}
