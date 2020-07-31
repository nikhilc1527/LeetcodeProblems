#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <algorithm>

class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& domino) {
    int ans=0;
    std::map<std::pair<int,int>, int> count;
    for(auto v : domino) {
      std::sort(v.begin(),v.end());

      auto p=std::make_pair(v[0],v[1]);
      
      count[p]++;
      
      if(count[p]==2)
	ans++;
      else if(count[p]>2)
	ans += count[p]-1;
    }
    return ans;
  }
};

int main() {
  std::vector<std::vector<int>> dominoes = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
  std::cout << Solution().numEquivDominoPairs(dominoes) << std::endl;
}
