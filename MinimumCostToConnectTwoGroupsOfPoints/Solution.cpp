#include <bitset>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  int connectTwoGroups(std::vector<std::vector<int>>& cost) {
    auto comp = [&](auto i, auto j) {
      return cost[i.first][i.second] > cost[j.first][j.second];
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        decltype(comp)>
        pq(comp);
    for (int i = 0; i < cost.size(); ++i) {
      for (int j = 0; j < cost[i].size(); ++j) {
        pq.push({i, j});
      }
    }
    // unsigned int a = (1 << n) - 1, b = (1 << n) - 1;
    std::bitset<12> a(0), b(0);
    for (int i = 0; i < cost[0].size(); ++i) a[i] = b[i] = 1;
    int res = 0;
    while (a.to_ulong() || b.to_ulong()) {
      auto [i, j] = pq.top();
      pq.pop();
      // if (!(a & (1 << i)) && !(b & (1 << j))) continue;
      if (!a[i] && !b[j]) continue;
      // a &= ~(1u << i);
      a[i] = 0;
      // b &= ~(1u << j);
      b[j] = 0;
      res += cost[i][j];
      std::cout << i << ", " << j << "\n";
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> cost = {{1, 3, 5}, {4, 1, 1}, {1, 5, 3}};
  int res = Solution().connectTwoGroups(cost);

  std::cout << res << "\n";

  return 0;
}
