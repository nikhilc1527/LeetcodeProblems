#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>

class Solution {
public:
  int xDir[4] = {1, 0, -1, 0};
  int yDir[4] = {0, 1, 0, -1};

  void dfs(int r, int c, std::vector<std::vector<int>>& grid, bool **visited, int color) {
    visited[r][c] = true;
        
    int same = 0;
        
    for(int k = 0; k < 4; k++) {
      int i = r + xDir[k], j = c + yDir[k];
              
      if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        continue;
            
      if(visited[i][j]) {
        same++;
        continue;
      }
            
      if(grid[i][j] == grid[r][c]) {
        dfs(i, j, grid, visited, color);
        same++;
      }
    }
        
    if(same < 4)
      grid[r][c] = color;
  }
    
  std::vector<std::vector<int>> colorBorder(std::vector<std::vector<int>>& grid, int r0, int c0, int color) {
    bool **visited;
    visited = new bool*[grid.size()];
        
    for(int i = 0; i < grid.size(); i++) {
      visited[i] = new bool[grid[0].size()];
            
      for(int j = 0; j < grid[0].size(); j++)
        visited[i][j] = false;
    }
        
    dfs(r0, c0, grid, visited, color);

    for (int i = 0; i < grid.size(); i++) {
      delete [] visited[i];
    }

    delete [] visited;
        
    return grid;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> grid =
  { {1, 1, 1},
    {1, 1, 1},
    {1, 1, 1} };

  auto res = Solution().colorBorder(grid, 0, 0, 2);

  for (auto &i : res) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
