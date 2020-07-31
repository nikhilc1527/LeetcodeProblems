#include <vector>
#include <climits>
#include <fstream>
#include <iostream>

class Solution {
public:
  int jump(std::vector<int>& nums) {
    if(nums.size() == 1)
      return 0;
    
    int jumps    = 0;
    int maxReach = nums[0];
    int steps    = nums[0];

    for (int i = 1; i < nums.size() - 1; i++) {
      maxReach = std::max(maxReach, i + nums[i]);
      steps--;
      if (steps == 0) {
        jumps++;
        steps = maxReach - i;
      }
    }
    return jumps + 1;
  }
};

int main(int argc, char *argv[]) {
  std::ifstream input("input.txt");
  std::string current;
  std::vector<int> input_vec;

  while (std::getline(input, current, ',')) {
    input_vec.push_back(std::stoi(current));
  }

  std::cout << input_vec.size() << '\n';

  std::cout << Solution().jump(input_vec) << '\n';

  return 0;
}

