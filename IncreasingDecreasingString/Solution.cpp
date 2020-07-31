#include <string>
#include <algorithm>
#include <map>

class Solution {
public:
  std::string sortString(std::string s) {
    std::map<char, int> freqs;
    for (int i = 0; i < s.size(); i++) {
      freqs[s[i] - 'a']++;
    }

    std::string res;
    unsigned int i = 0;
    while (i < s.size()) {
      for (auto it = freqs.begin(); it != freqs.end(); it++) {
	if (it->second > 0) {
	  res += it->first + 'a';
	  it->second--;
	  i++;
	}
	if (i == s.size()) break;
      }
      for (auto it = freqs.rbegin(); it != freqs.rend(); it++) {
	if (it->second > 0) {
	  res += it->first + 'a';
	  it->second--;
	  i++;
	}
	if (i == s.size()) break;
      }
    }
    return res;
  }
};
