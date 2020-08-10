#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
  bool canConvertString(std::string s, std::string t, int k) {
    if (s.size() != t.size()) return false;
    int moves = 0;
    std::vector<int> diffs;
    for (int i = 0; i < s.size(); ++i) {
      int diff = std::max(t[i] - s[i], s[i] - t[i]);
      if (diff > 0) 
      diffs.push_back(diff);
    }
    std::sort(diffs.begin(), diffs.end());
    int j = 0;
    for (int i = 0; i < diffs.size(); i++) {
      if (i < diffs.size() - 1 && diffs[i + 1] == diffs[i]) return false;
      if (diffs[j] == i) j = i;
    }
    return j <= k;
  }
};

int main(int argc, char *argv[]) {
  std::cout << std::boolalpha << Solution().canConvertString("input", "ouput", 9) << '\n';
  
  return 0;
}
