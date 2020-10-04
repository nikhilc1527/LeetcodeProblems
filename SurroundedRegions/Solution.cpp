#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

class Solution {
 public:
  void solve(std::vector<std::vector<char>>& board) {
    if (board.size() == 0) {
      return;
    }

    std::vector<std::set<std::pair<int, int>>> sets;

    auto on_edge = [&board](int x, int y) {
      return x <= 0 || x >= board.size() - 1 || y <= 0 ||
             y >= board[x].size() - 1;
    };

    auto find = [&sets](int x, int y) {
      for (int i = 0; i < sets.size(); i++) {
        if (sets[i].count({x, y})) {
          return i;
        }
      }
      return -1;
    };

    auto merge = [&sets](int i, int j) {
      sets[i].merge(sets[j]);
      sets.erase(sets.begin() + j);
    };

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == 'X') continue;

        int a = -1;
        bool b = false;
        if (j > 0 && board[i][j - 1] == 'O') {
          int k = find(i, j - 1);
          sets[k].insert({i, j});
          a = k;
          b = true;
        }
        if (i > 0 && board[i - 1][j] == 'O') {
          int k = find(i - 1, j);
          sets[k].insert({i, j});
          if (a >= 0 && a != k) {
            merge(a, k);
          }
          b = true;
        }
        if (!b) {
          sets.push_back({{i, j}});
        }
      }
    }

    for (auto& i : sets) {
      std::for_each(i.begin(), i.end(), [](auto j) {
        std::cout << "(" << j.first << ", " << j.second << ") ";
      });
      std::cout << "\n";
    }

    for (auto& i : sets) {
      auto pos = std::find_if(i.begin(), i.end(), [&on_edge](auto j) {
        return on_edge(j.first, j.second);
      });
      if (pos == i.end()) {
        std::for_each(i.begin(), i.end(),
                      [&board](auto j) { board[j.first][j.second] = 'X'; });
      }
    }
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::vector<std::vector<char>> board = {{'X', 'O', 'X', 'O', 'X', 'O'},
                                          {'O', 'X', 'O', 'X', 'O', 'X'},
                                          {'X', 'O', 'X', 'O', 'X', 'O'},
                                          {'O', 'X', 'O', 'X', 'O', 'X'}};

  s.solve(board);

  for (auto& i : board) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
