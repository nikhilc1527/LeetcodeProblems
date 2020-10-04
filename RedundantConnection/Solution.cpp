#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

/*
class Solution {
 public:
  std::vector<int> findRedundantConnection(
      std::vector<std::vector<int>>& edges) {
    int n = -1;
    std::for_each(edges.begin(), edges.end(),
                  [&n](const auto& edge) { n = std::max(n, edge[1]); });
    std::vector<std::set<int>> sets(n + 1);
    for (int i = 0; i < sets.size(); ++i) {
      sets[i].insert(i);
    }

    auto find = [&sets](int j) {
      for (int i = 0; i < sets.size(); ++i) {
        if (sets[i].count(j)) return i;
      }
      return -1;
    };

    auto merge = [&sets](int i, int j) {
      sets[i].merge(sets[j]);
      sets.erase(sets.begin() + j);
    };

    for (int i = 0; i < edges.size(); i++) {
      auto x = find(edges[i][0]), y = find(edges[i][1]);
      if (x == y) return edges[i];
      merge(x, y);
    }
    return {};
  }
};
*/

class Solution {
  class unionFind {
   public:
    std::vector<int> s;
    unionFind(int n) {
      for (int i = 0; i <= n; i++) {
        s.push_back(i);
      }
    }
    int find(int a) {
      if (a != s[a]) s[a] = find(s[a]);
      return s[a];
    }
    void unite(int a, int b, std::vector<int>& ans) {
      int a1 = find(a);
      int b1 = find(b);
      if (a1 == b1) {
        ans = {a, b};
        return;
      }
      s[a1] = b1;
    }
  };

 public:
  std::vector<int> findRedundantConnection(
      std::vector<std::vector<int>>& edges) {
    int maxnum = 0;
    for (auto m : edges) {
      maxnum = std::max(maxnum, std::max(m[0], m[1]));
    }
    unionFind graph(maxnum);
    std::vector<int> ans;
    for (auto m : edges) {
      graph.unite(m[0], m[1], ans);
      if (ans.size() > 0) break;
    }
    return ans;
  }
};

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};

  auto res = Solution().findRedundantConnection(edges);
  std::cout << res[0] << ", " << res[1] << "\n";

  return 0;
}
