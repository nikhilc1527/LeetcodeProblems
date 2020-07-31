#include <vector>

class Solution {
public:
  bool check(std::vector<bool> &vis, std::vector<bool> &globVis, int n, std::vector<std::vector<int>> &pres, int i) {
    if (vis[i]) return true;
    if (globVis[i]) return false;
    vis[i] = true;
    globVis[i] = true;

    for (auto j : pres[i]) {
      if (check(vis, globVis, n, pres, j)) return true;
    }

    vis[i] = false;

    return false;
  }
  
  bool canFinish(int n, std::vector<std::vector<int>>& pres) {
    std::vector<bool> vis(n), globVis(n);

    std::vector<std::vector<int>> adjList(n);
    for (auto &i : pres) {
      adjList[i[0]].push_back(i[1]);
    }

    for (int i = 0; i < n; i++) {
      if (!globVis[i]) {
	vis.assign(n, false);
	if (check(vis, globVis, n, adjList, i)) return false;
      }
    }

    return true;
  }
};
