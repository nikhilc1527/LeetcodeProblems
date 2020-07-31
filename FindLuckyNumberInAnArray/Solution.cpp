#include <vector>
#include <cstring>

class Solution {
public:
  int findLucky(std::vector<int>& arr) {
    int freq[501] = {0};
    for (auto i : arr) {
      freq[i]++;
    }
    int i = 500;
    for (; i >= 0; i--) {
      if (freq[i] == i - 1) break;
    }

    return i;
  }
};
