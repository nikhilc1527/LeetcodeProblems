#include <vector>
#include <string>
#include <string_view>
#include <iostream>

class Solution {
public:
  bool dfs(std::vector<std::vector<char>> &board, int i, int j, std::string_view word, std::vector<std::vector<bool>> &visited) {
    if (word.size() == 0) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
    if (visited[i][j]) return false;
    if (board[i][j] != word[0]) return false;
    visited[i][j] = true;
    bool res =
      dfs(board, i - 1, j, word.substr(1, word.size()), visited) ||
      dfs(board, i + 1, j, word.substr(1, word.size()), visited) ||
      dfs(board, i, j + 1, word.substr(1, word.size()), visited) ||
      dfs(board, i, j - 1, word.substr(1, word.size()), visited);
    visited[i][j] = false;
    return res;
  }
  
  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
	if (dfs(board, i, j, word, visited)) return true;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::string target = "ABCCED";
  Solution().exist(board, target);
  target = "SEE";
  Solution().exist(board, target);
  target = "ABCB";
  Solution().exist(board, target);
  
  return 0;
}
