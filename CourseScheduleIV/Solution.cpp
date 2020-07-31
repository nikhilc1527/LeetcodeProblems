#include <vector>
#include <deque>

class Solution {
public:
  std::vector<bool> checkIfPrerequisite(int n, std::vector<std::vector<int>>& ps, std::vector<std::vector<int>>& qs) {
    std::deque<int> sorted = topSort(ps, n);
    
  }
    
  std::deque<int> topSort(std::vector<std::vector<int>> &graph, int n) {
    std::vector<bool> visited(n, false);
    std::vector<std::vector<int>> adjList(n);
    for (auto &edge : graph) {
      adjList[edge[0]].push_back(edge[1]);
    }

    
  }

};
