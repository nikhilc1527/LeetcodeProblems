#include <iostream>
#include <map>
#include <utility>
#include <vector>

struct Solution {
  std::map<int, std::pair<int, int>> squares;
  std::vector<int> s;

  int find(int i) {
    if (s[i] != i) s[i] = find(s[i]);
    return s[i];
  }

  int swimInWater(std::vector<std::vector<int>>& grid) {
    auto out_of_bounds = [&](int i, int j) {
      return i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size();
    };

    auto unite = [&](int a, int b) {
      int a_par = find(a);
      int b_par = find(b);
      if (a_par != b_par) s[a_par] = b_par;
    };
    int max = grid.size() * grid.size() - 1;

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        squares[grid[i][j]] = {i, j};
      }
    }

    for (int i = 0; i <= max; ++i) s.push_back(i);

    for (auto& i : squares) {
      auto [time, pt] = i;
      auto [x, y] = pt;

      if (x > 0 && grid[x - 1][y] < time) {
        unite(time, grid[x - 1][y]);
      }
      if (x < grid.size() - 1 && grid[x + 1][y] < time) {
        unite(time, grid[x + 1][y]);
      }
      if (y > 0 && grid[x][y - 1] < time) {
        unite(time, grid[x][y - 1]);
      }
      if (y < grid[x].size() - 1 && grid[x][y + 1] < time) {
        unite(time, grid[x][y + 1]);
      }

      if (find(grid[0][0]) == find(grid[grid.size() - 1][grid[0].size() - 1])) {
        return time;
      }
    }
    return max;
  }
};

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> grid = {{0, 1, 2, 3, 4},
                                        {24, 23, 22, 21, 5},
                                        {12, 13, 14, 15, 16},
                                        {11, 17, 18, 19, 20},
                                        {10, 9, 8, 7, 6}};
  int res = Solution().swimInWater(grid);
  std::cout << res << "\n";

  return 0;
}
