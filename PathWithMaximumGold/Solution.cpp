#include <vector>
#include <iostream>

class Solution {
public:
  int dfs(std::vector<std::vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) return 0;
    if (grid[i][j] <= 0) return 0;

    grid[i][j] = -grid[i][j];

    int max = -1;
    max = std::max(max, dfs(grid, i - 1, j));
    max = std::max(max, dfs(grid, i + 1, j));
    max = std::max(max, dfs(grid, i, j - 1));
    max = std::max(max, dfs(grid, i, j + 1));

    grid[i][j] = -grid[i][j];

    return max + grid[i][j];
  }
  
  int getMaximumGold(std::vector<std::vector<int>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) return 0;

    int maxSum = -1;
    for (size_t i = 0; i < grid.size(); i++) {
      for (size_t j = 0; j < grid[i].size(); j++) {
	maxSum = std::max(maxSum, dfs(grid, i, j));
      }
    }

    return maxSum;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> grid = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
  std::cout << Solution().getMaximumGold(grid) << "\n";
  grid = {{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}};
  std::cout << Solution().getMaximumGold(grid) << "\n";

  return 0;
}
