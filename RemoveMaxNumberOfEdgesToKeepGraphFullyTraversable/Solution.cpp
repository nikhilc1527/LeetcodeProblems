#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  struct union_find {
    int num_comps;
    std::vector<int> s;
    union_find(int n) : num_comps(n) {
      for (int i = 0; i <= n; ++i) {
        s.push_back(i);
      }
    }

    int find(int i) {
      if (s[i] != i) s[i] = find(s[i]);
      return s[i];
    }

    bool unite(int a, int b) {
      a = find(a);
      b = find(b);
      if (s[a] != s[b]) {
        s[a] = b;
        --num_comps;
        return true;
      } else
        return false;
    }
  };
  int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
    std::sort(edges.begin(), edges.end(),
              [](const auto& i, const auto& j) { return i[0] > j[0]; });

    union_find a(n), b(n);
    int res = 0;
    for (int i = 0; i < edges.size(); ++i) {
      int type = edges[i][0], u = edges[i][1], v = edges[i][2];

      if (type == 1) {
        if (a.num_comps == 1)
          ++res;
        else if (!a.unite(u, v))
          ++res;
      }

      else if (type == 2) {
        if (b.num_comps == 1)
          ++res;
        else if (!b.unite(u, v))
          ++res;
      }

      else if (type == 3) {
        if (a.num_comps == 1 && b.num_comps == 1)
          ++res;
        else {
          bool a_gud = a.unite(u, v), b_gud = b.unite(u, v);
          if (!a_gud && !b_gud) ++res;
        }
      }
    }

    return a.num_comps > 1 || b.num_comps > 1 ? -1 : res;
  }
};

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3},
                                         {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
  int n = 4;
  int res = Solution().maxNumEdgesToRemove(n, edges);

  std::cout << res << "\n";

  return 0;
}
