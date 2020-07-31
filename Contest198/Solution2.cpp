#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
  std::vector<int> countSubTrees(int n, std::vector<std::vector<int>>& edges, std::string labels) {
    std::vector<std::vector<int>> adjList(n);
    std::vector<bool> vis(n, false);
    for (auto &i : edges) {
      adjList[i[0]].push_back(i[1]);
      adjList[i[1]].push_back(i[0]);
    }

    std::vector<int> res(n);
    countLabels(adjList, 0, labels, res, vis);
    
    return res;
  }

  std::vector<int> countLabels(std::vector<std::vector<int>> &adjList, int i, std::string &labels, std::vector<int> &result, std::vector<bool> &vis) {
    std::vector<int> res(26, 0);
    if (vis[i]) return res;
    vis[i] = true;
    res[labels[i] - 'a']++;

    for (auto j : adjList[i]) {
      std::vector<int> next = countLabels(adjList, j, labels, result, vis);
      for (int i = 0; i < 26; i++) {
	res[i] += next[i];
      }
    }
    result[i] = res[labels[i] - 'a'];
    return res;
  }
};

int main() {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 2}, {0, 3}, {1, 2}};
  std::string labels = "aeed";
  std::vector<int> res = Solution().countSubTrees(n, edges, labels);
  for (auto i : res) {
    std::cout << i << '\n';
  }
}

