#include <vector>
#include <algorithm>

#include "../utils.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1, k = nums.size() - 1; j < k;) {
	int sum = nums[i] + nums[j] + nums[k];
	if (sum == 0) {
	  res.push_back({nums[i], nums[j], nums[k]});
	  j++;
	  k--;
	  
	  while (j > 0 && j < nums.size() && nums[j] == nums[j - 1]) j++;
	  while (k < nums.size() - 1 && k >= 0 && nums[k] == nums[k + 1]) k--;
	}
	else if (sum < 0)
	  j++;
	else k--;
      }
      while (i < nums.size() - 1 && nums[i + 1] == nums[i]) i++;
    }
    
    return res;
  }
};

int main() {
  vector<int> input = {0,0,0,0};
  Solution s;
  vector<vector<int>> res = s.threeSum(input);
  utils::print_2d_vector(res);
}
