#include <string>

class Solution {
public:
  int numSub(std::string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      while (s[i] == '0') i++;
      int j = i;
      while (j < s.size() && s[j] == '1') j++;
      res += (j - i) * (j - i + 1) / 2;
      i = j + 1;
    }

    return res;
  }
};
