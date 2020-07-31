#include <string>
#include <algorithm>
#include <queue>

class Solution {
public:
  // #5. Longest Palindromic Substring (Medium)
  std::string longestPalindrome(std::string s) {
    std::size_t size = s.size();
    if (!size) return "";
    std::size_t resSize = 0, resStart;
    std::size_t i = 0, j, k;
    for (i = 0; i < size; i++) {
      j = i;
      for (; j < size - 1 && s[i] == s[j+1]; j++);
      k = j;
      if (std::min(i, size - 1 - j) * 2 + (j - i + 1) > resSize) {
	for (; i > 0 && j < size - 1 && s[i - 1] == s[j + 1]; i--, j++);
	if (j - i + 1 > resSize) {
	  resStart = i;
	  resSize = j - i + 1;
	}
      }

      i = k;
    }

    return s.substr(resStart, resSize);
  }

  std::string longestPalindrome2(std::string s) {
    std::deque<std::pair<int, int>> q;
    
    for (std::size_t i = 0; i < s.size(); i++) {
      std::size_t j = i;
      while (j < s.size() - 1 && s[j + 1] == s[i]) j++;
      q.push_back({i, j});
      i = j;
    }
    std::size_t maxSize = 0, maxStart = 0;
    
    while (!q.empty()) {
      auto ij = q.front();
      q.pop_front();
      if (ij.first > 0 && ij.second < s.size() - 1 &&
	  s[ij.first - 1] == s[ij.second + 1]) {
	q.push_back({ij.first-1, ij.second+1});
      }
      else if (ij.second - ij.first + 1 > maxSize) {
        maxSize = ij.second - ij.first + 1;
	maxStart = ij.first;
      }
    }

    return s.substr(maxStart, maxSize);
  }

};
