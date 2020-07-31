#include <string>
#include <vector>
#include <iostream>

class Solution {
 public:
  int maxScore(std::string s) {
    if (s.empty()) return 0;
    std::vector<int> ls, rs;
    unsigned int lnum = 0, rnum = 0;
    for (int i = 0, j = s.size() - 1; i < s.size() && j >= 0; i++, j--) {
      if (s[i] == '0')
	lnum++;
      if (s[j] == '1')
	rnum++;
      ls[i] = lnum;
      rs[i] = rnum;
    }
        
    int max = -1;
    for (int i = 0; i < s.size(); i++) {
      max = std::max(max, ls[i] + rs[i]);
    }
        
    return max;
  }
};

int main() {
  Solution s;
  std::cout << s.maxScore("011101") << std::endl;
}
