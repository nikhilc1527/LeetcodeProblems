#include <string>

class Solution {
public:
  int minInsertions(std::string s) {
    int res = 0;
    int open = 0, close = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        open++;
      }
      else {
        close++;
        
        if (close > 2*open) {
          if (
        }
      }
    }

    return open * 2 + res;
  }
};
