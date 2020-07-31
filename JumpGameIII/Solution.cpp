#include <vector>

class Solution {
public:
  bool helper(std::vector<int> &arr, int i, std::vector<bool> &memo) {
    if (i < 0 || i >= arr.size()) return false;
    if (memo[i]) {
      return false;
    }
    if (arr[i] == 0) {
      return true;
    }
    memo[i] = true;
    auto res = helper(arr, i - arr[i], memo) || helper(arr, i + arr[i], memo);
    if (res) return true;
    return false;
  }
  
  bool canReach(std::vector<int>& arr, int start) {
    std::vector<bool> memo(arr.size(), false);
    return helper(arr, start, memo);
  }
};
