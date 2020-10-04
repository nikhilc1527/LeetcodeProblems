#include <vector>
#include <algorithm>

class Solution {
public:
  int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [] (auto &i, auto &j) {
                return i[0] < j[0];
              });
    
  }
};
