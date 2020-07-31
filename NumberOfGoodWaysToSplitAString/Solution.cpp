#include <string>
#include <vector>
#include <array>

class Solution {
public:
  int numSplits(std::string s) {
    std::array<bool, 26> seenForward, seenBackward;
    std::vector<int> forward, backward;
    int curCount = 0;
    for (int i = 0; i < s.size(); i++) {
      char& cur = s[i];
      
    }
  }
};
