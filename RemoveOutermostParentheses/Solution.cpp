#include <string>
#include <string_view>
#include <vector>

class Solution {
public:
  std::string removeOuterParentheses(std::string s) {
    int count = 1;
    int begin = 0;
    std::vector<std::string_view> res;
    for (int i = 1; i < s.size(); i++) {
      count += s[i] == '(' ? 1 : -1;
      if (count == 0) {
	res.emplace_back(s.begin() + begin, i - begin);
      }
      
    }
  }
};
