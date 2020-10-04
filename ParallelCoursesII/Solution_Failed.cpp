#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

class Solution {
 public:
  void top_sort(int n, std::vector<std::vector<int>>& adj_list,
                std::vector<int>& res, std::vector<std::set<int>>& deps,
                std::vector<bool>& vis, int i, int prev) {
    if (prev != -1) deps[i].insert(prev);
    if (vis[i]) return;
    vis[i] = true;

    for (auto& j : adj_list[i]) {
      top_sort(n, adj_list, res, deps, vis, j, i);
    }
  }

  std::vector<int> no_pars(int n, std::vector<std::vector<int>>& edge_list) {
    std::vector<bool> par(n + 1);
    for (auto& i : edge_list) {
      par[i[1]] = true;
    }
    std::vector<int> res;
    for (int i = 1; i <= n; i++) {
      if (!par[i]) res.push_back(i);
    }
    return std::move(res);
  }

  int minNumberOfSemesters2(int n, std::vector<std::vector<int>>& dependencies,
                            int k) {
    std::vector<std::set<int>> deps(n + 1);
    std::vector<std::vector<int>> adj_list(n + 1);
    std::vector<int> top_sorted;

    for (auto& i : dependencies) {
      adj_list[i[0]].push_back(i[1]);
    }
    std::vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
      top_sort(n, adj_list, top_sorted, deps, vis, i, -1);
    }

    auto no_parents = no_pars(n, dependencies);
    std::deque<int> q;
    for (auto i : no_parents) q.push_back(i);
    std::set<int> seen;
    while (!q.empty()) {
      std::deque<int> copy = q;
      std::sort(copy.begin(), copy.end(), [&adj_list](auto i, auto j) {
        return adj_list[i].size() > adj_list[j].size();
      });
      q.clear();
      for (auto j : copy) {
        top_sorted.push_back(j);
        for (auto i : adj_list[j]) {
          if (!seen.count(i)) {
            q.push_back(i);
            seen.insert(i);
          }
        }
      }
    }

    for (auto i : top_sorted) {
      std::cout << i << "\n";
    }

    for (auto& i : deps) {
      for (auto j : i) {
        std::cout << j;
      }
      if (i.empty()) std::cout << "------";
      std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "\n";

    int res = 0;
    std::vector<std::set<int>> new_deps = deps;
    for (int i = 0, j = 0; i < top_sorted.size(); i++) {
      bool a = false;
      if (i - j == k) {
        res++;
        std::cout << i << "\n";
        j = i;
        a = true;

        deps = new_deps;
      }

      if (!deps[top_sorted[i]].empty()) {
        j = i;
        if (!a) {
          res++;
          std::cout << i << "\n";
        }

        deps = new_deps;
      }

      for (auto j : adj_list[top_sorted[i]]) {
        auto pos =
            std::find(new_deps[j].begin(), new_deps[j].end(), top_sorted[i]);
        new_deps[j].erase(pos);
      }

      // deps = new_deps;
    }

    return res + 1;
  }

  int minNumberOfSemesters(int n, std::vector<std::vector<int>>& edge_list,
                           int k) {
    std::vector<std::set<int>> deps(n + 1);
    std::vector<std::set<int>> adj_list(n + 1);
    std::vector<int> top_sorted;
    for (auto& i : edge_list) {
      deps[i[1]].insert(i[0]);
      adj_list[i[0]].insert(i[1]);
    }

    for (int k = 0; k < adj_list.size(); k++) {
      auto i = adj_list[k];
      std::cout << k << ": ";
      for (auto j : i) {
        std::cout << j << " ";
      }
      std::cout << "\n";
    }

    std::cout << "\n";
    std::cout << "\n";

    for (int k = 0; k < deps.size(); k++) {
      auto i = deps[k];
      std::cout << k << ": ";
      for (auto j : i) {
        std::cout << j << " ";
      }
      std::cout << "\n";
    }

    std::cout << "\n";
    std::cout << "\n";

    auto get_depth = [&adj_list](int i, auto&& get_depth) {
      if (adj_list[i].size() == 0)
        return 1;
      else {
        int max = -1;
        for (auto j : adj_list[i]) {
          max = std::max(max, get_depth(j, get_depth));
        }
        return max + 1;
      }
    };

    std::deque<int> cur_nums;
    {
      auto no_parents = no_pars(n, edge_list);
      for (auto i : no_parents) cur_nums.push_back(i);
      // cur_nums.insert(cur_nums.end(), no_parents.begin(), no_parents.end());
    }

    int res = 0;
    std::set<int> seen;

    while (!cur_nums.empty()) {
      int cur_size;

      std::sort(cur_nums.begin(), cur_nums.end(),
                [&, next_level = 0](auto i, auto j) mutable {
                  if (deps[i].size() != deps[j].size()) {
                    return deps[i].size() > deps[j].size();
                  }
                  auto depth_1 = get_depth(i, get_depth),
                       depth_2 = get_depth(j, get_depth);

                  return adj_list[i].size() == adj_list[j].size()
                             ? depth_1 > depth_2
                             : adj_list[i].size() > adj_list[j].size();
                });

      for (auto i : cur_nums) {
        std::cout << "-->" << i << "\n";
        if (deps[i].size() > 0)
          for (auto i : deps[i]) {
            std::cout << i << "\n";
          }
        else
          std::cout << "None"
                    << "\n";
      }
      std::cout << "Current size: " << cur_nums.size() << "\n";

      // std::sort(cur_nums.begin(), cur_nums.end(), [&deps](auto i, auto j) {
      //   return deps[i].size() > deps[j].size();
      // });

      int cur_len = cur_nums.size();
      std::vector<int> erased;

      int j = 0;
      while (deps[cur_nums[j]].size() > 0) ++j;

      if (cur_nums.size() - j <= k) {
        cur_size = cur_len - j;
      } else {
        cur_size = k;
      }

      int erase_pos = j;

      for (int i = 0; i < cur_size; i++) {
        if (deps[cur_nums[erase_pos]].size() > 0) {
          cur_size++;
          erase_pos++;
          continue;
        }
        for (auto j : adj_list[cur_nums[erase_pos]]) {
          auto pos =
              std::find(deps[j].begin(), deps[j].end(), cur_nums[erase_pos]);
          if (pos != deps[j].end()) deps[j].erase(pos);
          if (!seen.count(j)) {
            cur_nums.push_back(j);
            seen.insert(j);
          }
        }
        erased.push_back(cur_nums[erase_pos]);
        cur_nums.erase(cur_nums.begin() + erase_pos);
      }

      std::cout << "Erased: ";
      for (auto i : erased) std::cout << i << " ";
      std::cout << "\n";
      std::cout << "\n";

      res++;
    }

    return res;
  }

  int minNumberOfSemesters3(int n, std::vector<std::vector<int>>& edge_list,
                            int k) {
    std::vector<int> deps(n + 1);
    std::vector<std::set<int>> adj_list(n + 1);
    std::vector<int> top_sorted;
    for (auto& i : edge_list) {
      ++deps[i[1]];
      adj_list[i[0]].insert(i[1]);
    }

    for (int k = 0; k < adj_list.size(); k++) {
      auto i = adj_list[k];
      std::cout << k << ": ";
      for (auto j : i) {
        std::cout << j << " ";
      }
      std::cout << "\n";
    }

    std::cout << "\n";
    std::cout << "\n";

    auto get_depth = [&adj_list](int i, auto&& get_depth) {
      if (adj_list[i].size() == 0)
        return 1;
      else {
        int max = -1;
        for (auto j : adj_list[i]) {
          max = std::max(max, get_depth(j, get_depth));
        }
        return max + 1;
      }
    };

    struct Comp {
      bool operator()(std::pair<int, int> i, std::pair<int, int> j) {
        return i.second < j.second;
      }
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        Comp>
        cur_numsu;
    for (int i = 1; i <= n; ++i) {
      if (deps[i] == 0) {
        cur_numsu.emplace(i, 0);
      }
    }

    int res = 0;
    std::set<int> seen;

    while (!cur_numsu.empty()) {
      int cur_size;

      int cur_len = cur_numsu.size();
      std::vector<int> erased;

      cur_size = std::min(cur_len, k);

      for (int i = 0; i < cur_size; i++) {
        auto cur = cur_numsu.top();
        cur_numsu.pop();
        for (auto j : adj_list[cur.first]) {
          --deps[j];
          if (deps[j] == 0 && !seen.count(j)) {
            cur_numsu.emplace(j, cur.second + 1);
            seen.insert(j);
          }
        }
        erased.push_back(cur.first);
      }

      std::cout << "Erased: ";
      for (auto i : erased) std::cout << i << " ";
      std::cout << "\n";
      std::cout << "\n";

      res++;
    }

    return res;
  }
};

int main(int argc, char* argv[]) {
  // int n = 4;
  // std::vector<std::vector<int>> deps = {{2, 1}, {3, 1}, {1, 4}};
  // int k = 2;
  // int n = 12;
  // std::vector<std::vector<int>> deps = {{1, 2},  {1, 3},   {7, 5},
  //                                       {7, 6},  {4, 8},   {8, 9},
  //                                       {9, 10}, {10, 11}, {11, 12}};
  // int k = 2;
  // int n = 5;
  // std::vector<std::vector<int>> deps = {{2, 1}, {3, 1}, {4, 1}, {1, 5}};
  // int k = 2;
  // int n = 15;
  // std::vector<std::vector<int>> deps = {
  //     {10, 2}, {15, 3}, {9, 14}, {13, 1}, {5, 14},  {5, 6},   {12, 11},
  //     {9, 13}, {13, 3}, {9, 8},  {12, 3}, {5, 9},   {15, 10}, {10, 6},
  //     {7, 1},  {9, 7},  {15, 4}, {3, 14}, {5, 1},   {13, 10}, {5, 13},
  //     {15, 7}, {5, 11}, {13, 2}, {10, 8}, {15, 2},  {14, 11}, {15, 13},
  //     {12, 1}, {15, 6}, {12, 5}, {5, 2},  {12, 13}, {13, 14}, {8, 6},
  //     {10, 4}, {1, 11}, {4, 1},  {6, 11}, {9, 3},   {2, 6},   {4, 2}};
  // int k = 4;
  // int n = 9;
  // std::vector<std::vector<int>> deps = {{1, 5}, {2, 5}, {3, 5}, {4, 6},
  //                                       {4, 7}, {4, 8}, {4, 9}};
  // int k = 3;

  // int n = 12;
  // std::vector<std::vector<int>> deps = {
  //     {11, 10}, {6, 3}, {2, 5}, {9, 2}, {4, 12}, {8, 7}, {9, 5},
  //     {6, 2},   {7, 2}, {7, 4}, {9, 3}, {11, 1}, {4, 3}};
  // int k = 3;

  auto res = Solution().minNumberOfSemesters(n, deps, k);

  std::cout << "Result: " << res << "\n";

  return 0;
}
