#include <vector>
#include <iostream>

class Solution {
public:
  bool sort(std::vector<bool> &vis, std::vector<bool> &globVis, int n, std::vector<std::vector<int>> &pres, int i, std::vector<int> &res) {
    if (vis[i]) return true;
    if (globVis[i]) return false;
    vis[i] = true;
    globVis[i] = true;

    for (auto j : pres[i]) {
      if (sort(vis, globVis, n, pres, j, res)) return true;
    }

    res.push_back(i);

    vis[i] = false;

    return false;
  }

  std::vector<int> findOrder(int n, std::vector<std::vector<int>>& pres) {
    std::vector<int> res;
    std::vector<bool> vis(n), globVis(n);

    std::vector<std::vector<int>> adjList(n);
    for (auto &i : pres) {
      adjList[i[0]].push_back(i[1]);
    }

    for (int i = 0; i < n; i++) {
      if (!globVis[i]) {
	vis.assign(n, false);
	if (sort(vis, globVis, n, adjList, i, res)) return {};
      }
    }

    return res;
  }

};

int main() {
  int n = 4;
  std::vector<std::vector<int>> pres = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  std::vector<int> res = Solution().findOrder(n, pres);
  for (auto i : res) {
    std::cout << i << std::endl;
  }
}
