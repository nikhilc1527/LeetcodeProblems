#include <iostream>
#include <map>
#include <utility>
#include <vector>

using pt = std::pair<int, int>;

class union_find {
 public:
  std::map<pt, pt> s;

  pt find(pt a) {
    if (!s.count(a)) s[a] = a;
    if (a != s[a]) s[a] = find(s[a]);
    return s[a];
  }
  bool unite(pt a, pt b) {
    auto a1 = find(a);
    auto b1 = find(b);
    if (a1 != b1) {
      s[a1] = b1;
      return true;
    } else
      return false;
  }
};

class Solution {
 public:
  int removeStones(std::vector<std::vector<int>>& stones) {
    union_find uf;
    std::map<int, std::vector<int>> x, y;
    for (auto& i : stones) {
      if (x.count(i[0])) {
        for (auto j : x[i[0]]) {
          uf.unite({i[0], j}, {i[0], i[1]});
        }
      }
      if (y.count(i[1])) {
        for (auto j : y[i[1]]) {
          uf.unite({j, i[1]}, {i[0], i[1]});
        }
      }
      for (auto i : uf.s)
        std::cout << i.first.first << "," << i.first.second << ":"
                  << i.second.first << "," << i.second.second << '\n';
      std::cout << (!uf.s.size() ? "EMPTY" : "") << '\n';
      x[i[0]].push_back(i[1]);
      y[i[1]].push_back(i[0]);
    }

    int res = 0;
    for (auto i : uf.s)
      if (uf.find(i.first) != i.first) ++res;

    return res;
  }
};
/*
test cases
[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
[[0,0],[0,2],[1,1],[2,0],[2,2]]
[[0,0]]
[[0,1],[1,0],[1,1]]
[[0,1],[1,0]]
*/

/*
int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> stones = {{0, 1}, {1, 0}, {1, 1}};
  std::cout << Solution().removeStones(stones) << "\n";

  return 0;
}
*/
