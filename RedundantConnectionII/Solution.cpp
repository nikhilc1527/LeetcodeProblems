#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

class union_find {
 public:
  std::vector<int> s;
  int num_sets;
  union_find(int n) {
    for (int i = 0; i <= n; i++) {
      s.push_back(i);
    }
    num_sets = n;
  }
  int find(int a) {
    if (a != s[a]) s[a] = find(s[a]);
    return s[a];
  }
  bool unite(int a, int b) {
    int a1 = find(a);
    int b1 = find(b);
    if (a1 != b1) {
      s[a1] = b1;
      --num_sets;
      return true;
    } else
      return false;
  }
};

class Solution {
 public:
  std::vector<int> findRedundantDirectedConnection(
      std::vector<std::vector<int>>& edges) {
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      auto &i = *it;
      if (check_cycles(edges, i) && check_forest(edges, i)) return i;
    }
    return {};
  }

  bool check_cycles(std::vector<std::vector<int>>& edges,
                    std::vector<int> remove) {
    union_find uf(edges.size());
    for (auto& i : edges) {
      if (i == remove)
        continue;
      else if (!uf.unite(i[0], i[1]))
        return false;
    }
    return true;
  }

  bool check_forest(std::vector<std::vector<int>>& edges,
                    std::vector<int> remove) {
    std::vector<bool> par(edges.size() + 1, false);
    for (auto& i : edges) {
      if (i == remove) continue;
      if (par[i[1]]) return false;
      par[i[1]] = true;
    }
    return true;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::vector<std::vector<int>> edges{{1, 2}, {1, 3}, {2, 3}};

  auto res = s.findRedundantDirectedConnection(edges);
  std::cout << res[0] << ", " << res[1] << "\n";

  return 0;
}
