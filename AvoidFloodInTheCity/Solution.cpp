#include <vector>
#include <stack>
#include <unordered_set>

class Solution {
public:
  std::vector<int> avoidFlood(std::vector<int>& rains) {
    std::vector<int> res(rains.size());
    std::unordered_set<int> full;
    unsigned int i = 0;

    while (i < rains.size()) {
      if (rains[i] > 0) {
	if (full.count(rains[i])) return {};
	full.insert(rains[i]);
	res[i] = -1;
	i++;
      }
      else {
	unsigned int j = i + 1;
	while (!rains[j]) j++;
	int days = j - i;
	while (j < rains.size() && days >= 0) {
	  res[j] = -1;
	}
      }
    }
    
    return res;
  }
};
