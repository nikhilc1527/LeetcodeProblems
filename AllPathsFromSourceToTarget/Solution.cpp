#include <vector>

class Solution {
public:
  void dfs(int i, std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& res, std::vector<int> &curStack, int n) {
    curStack.push_back(i);
    if (i == n)
      res.push_back(curStack);
    else for (auto &j : graph[i])
           dfs(j, graph, res, curStack, n);
    curStack.pop_back();
  }
  
  std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> res;
    std::vector<int> stack;
    dfs(0, graph, res, stack, graph.size() - 1);
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
