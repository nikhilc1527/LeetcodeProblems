#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

class Solution {
  bool isPalindrome(int counts[10], int i, int j) {
    int res = 0;
    bool hasOdd = false;
    while (i < j) {
      if ((counts[i] & 1) == 0) res += 2;
      else if (hasOdd) return false;
      else hasOdd = true;
      i++;
    }
    return true;
  }
  
public:
  int longestAwesome(std::string s) {
    int counts[10]{0};
    for (auto c : s) {
      counts[c - '0']++;
    }
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      for (int j = s.size(); j > i; j--) {
        if (isPalindrome(counts, i, j)) {
          res = std::max(res, j - i);
        }
        if (j - i < res) break;
      }
    }

    return std::max(res, 1);
  }
};

int main(int argc, char *argv[]) {
  std::cout << Solution().longestAwesome("1234") << std::endl;
  
  return 0;
}
