#include <vector>
#include <cstring>
#include <iostream>

class Solution {
public:
  bool winnerSquareGame(int n, std::vector<char> &dp) {
    if (dp[n] > -1) {
      return dp[n];
    }

    bool res = false;
    for (int i = 1, k = 3; i <= n; i += k, k += 2) {
      bool nextMove = winnerSquareGame(n - i, dp);
      if (!nextMove) res = true;
    }

    return (dp[n] = res);
  }
  
  bool winnerSquareGame(int n) {
    std::vector<char> dp(n + 1, -1);
    dp[1] = 1;
    dp[0] = 0;

    return winnerSquareGame(n, dp);
  }
};

int main(int argc, char** argv) {
  int n;

  for (int i = 1; i < argc; i++) {
    n = std::stoi(argv[i]);
    std::cout << n << std::endl;
    bool res = Solution().winnerSquareGame(n);
    std::cout << std::boolalpha << res << std::endl << std::endl;
  }
}
