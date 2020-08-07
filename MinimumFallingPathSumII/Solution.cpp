#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
  void calcRow(std::vector<std::vector<int>> &orig, std::vector<std::vector<int>> &res, int i, int n) {
    int min = res[i][0];
    for (int j = 1; j < n; j++) {
      res[i - 1][j] = orig[i - 1][j] + min;
      min = std::min(min, res[i][j]);
    }

    min = res[i][n - 1];
    for (int j = n - 2; j >= 0; j--) {
      res[i - 1][j] = std::min(res[i - 1][j], orig[i - 1][j] + min);
      min = std::min(min, res[i][j]);
    }
  }
  
  int minFallingPathSum(std::vector<std::vector<int>>& arr) {
    int n = arr.size();
    std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
    std::copy(arr[n - 1].begin(), arr[n - 1].end(), res[n - 1].begin());
    for (int i = n - 1; i > 0; i--) {
      calcRow(arr, res, i, n);
    }

    return *std::max_element(res[0].begin(), res[0].end());
  }
};


int main(int argc, char *argv[]) {
  Solution s;
  std::vector<std::vector<int>> arr {
    {1, 2, 3}, {4, 5, 6}, { 7, 8, 9 }
  };

  std::cout << s.minFallingPathSum(arr) << '\n';

  return 0;
}

// 1 2 3
// 4 5 6
// 7 8 9
