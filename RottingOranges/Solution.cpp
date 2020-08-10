#include <vector>
#include <queue>
#include <utility>
#include <iostream>

class Solution {
public:
  int orangesRotting(std::vector<std::vector<int>>& grid) {
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == 2) {
          q.emplace(i, j);
          grid[i][j] = 0;
        }
      }
    }

    auto outOfBounds = [&grid] (int i, int j) {
                         return i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size();
                       };

    int time = 0;
    while (!q.empty()) {
      std::queue<std::pair<int, int>> newQ;
      while (!q.empty()) {
        auto [i, j] = q.front();
        for (int x = -1; x <= 1; ++x) {
          for (int y = -1; y <= 1; ++y) {
            if (std::abs(x) == std::abs(y)) continue;
            if (!outOfBounds(i + x, j + y) && grid[i+x][j+y] == 1) {
              newQ.emplace(i + x, j + y);
              grid[i + x][j + y] = 0;
            }
          }
        }
        q.pop();
      }        

      q = newQ;
      if (q.size() > 0)
        ++time;
    }

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j]) return -1;
      }
    }

    return time;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> grid =
    {
     {2, 2},
     {1, 1},
     {0, 0},
     {2, 0}};

  std::cout << Solution().orangesRotting(grid) << '\n';

  return 0;
}
