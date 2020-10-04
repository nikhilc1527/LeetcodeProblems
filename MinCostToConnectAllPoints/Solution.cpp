#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

/*
class Solution {
 public:
  using set_type = std::unordered_set<int>;

  int find(std::vector<set_type> &sets, int j) {
    for (int i = 0; i < sets.size(); ++i) {
      if (sets[i].count(j)) return i;
    }
    return -1;
  }

  void join(std::vector<set_type> &sets, int i, int j) {
    // for (auto k : sets[j]) sets[i].insert(k);
    sets[i].merge(sets[j]);
    sets.erase(sets.begin() + j);
  }

  int minCostConnectPoints(std::vector<std::vector<int>> &points) {
    if (points.size() == 0 || points.size() == 1) return 0;
    auto dist = [](int x, int y, int x2, int y2) {
      return abs(x2 - x) + abs(y2 - y);
    };

    std::vector<set_type> sets(points.size());
    std::vector<std::array<int, 3>> edges;  // weight, i, j
    // priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int,
    // 3>>> edges;

    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        // edges.push({dist(points[i][0], points[i][1], points[j][0],
        // points[j][1]), i, j});
        edges.push_back(
            {dist(points[i][0], points[i][1], points[j][0], points[j][1]), i,
             j});
      }
    }

    std::make_heap(edges.begin(), edges.end(),
                   [](auto i, auto j) { return i[0] > j[0]; });

    for (int i = 0; i < sets.size(); ++i) {
      sets[i].insert(i);
    }

    std::uint64_t res = 0;
    while (sets.size() > 1) {
      pop_heap(edges.begin(), edges.end(),
               [](auto i, auto j) { return i[0] > j[0]; });
      auto [weight, i, j] = edges[edges.size() - 1];
      // auto [weight, i, j] = edges.top();
      // edges.pop();
      edges.pop_back();
      auto i_set = find(sets, i), j_set = find(sets, j);
      if (i_set != j_set) {
        join(sets, i_set, j_set);
        res += weight;
      }
    }

    return (int)res;
  }
};
*/

class union_find {
 public:
  std::vector<int> par;
  union_find(int n) {
    for (int i = 0; i <= n; i++) {
      par.push_back(i);
    }
  }
  int find(int a) {
    if (a != par[a]) par[a] = find(par[a]);
    return par[a];
  }
  void unite(int a, int b) {
    int a_par = find(a);
    int b_par = find(b);
    par[a_par] = b_par;
  }
};

class Solution {
 public:
  int minCostConnectPoints(std::vector<std::vector<int>>& points) {
    if (points.size() == 0 || points.size() == 1) return 0;
    auto dist = [](int x, int y, int x2, int y2) {
      return abs(x2 - x) + abs(y2 - y);
    };

    std::vector<std::array<int, 3>> edges;  // weight, i, j
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        edges.push_back(
            {dist(points[i][0], points[i][1], points[j][0], points[j][1]), i,
             j});
      }
    }

    std::make_heap(edges.begin(), edges.end(),
                   std::greater<std::array<int, 3>>{});

    union_find uf(points.size());

    std::uint64_t res = 0, num_pts = 1;
    while (num_pts < points.size()) {
      pop_heap(edges.begin(), edges.end(), std::greater<std::array<int, 3>>{});
      auto [weight, i, j] = edges[edges.size() - 1];
      edges.pop_back();

      auto i_set = uf.find(i), j_set = uf.find(j);
      if (i_set != j_set) {
        uf.unite(i, j);
        res += weight;
        ++num_pts;
      }
    }

    return (int)res;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::vector<std::vector<int>> points = {
      {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

  auto res = s.minCostConnectPoints(points);
  std::cout << res << "\n";

  return 0;
}
