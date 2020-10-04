#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <array>

using namespace std;

class Solution {
public:
    int dfs(int n, vector<int> &a) {
        if (n <= 0) return 0;
        if (a[n] >= 0) {
            return a[n];
        }
        int res = INT_MAX;
        if (n % 3 == 0) {
          res = min(res, dfs(n / 3, a) + 1);
        }
        if (n % 2 == 0) {
          res = min(res, dfs(n / 2, a) + 1);
        }
        res = min(res, dfs(n - 1, a) + 1);
        cout << n << ", " << res << '\n';
        return a[n] = res;
    }
    
    int minDays(int n) {
        // vector<int> a(n + 1, -1);
        // a[0] = 0;
        // a[1] = 1;
        // return dfs(n, a);

      vector<int> arr (n + 1, INT_MAX);
      array<int, 2 * (size_t)1e9> a;
      a[0] = 0;
      a[1] = 1;
      for (int i = 0; i < a.size() - 1; i++) {
        a[i + 1] = min(a[i + 1], a[i] + 1);
        if (i * 2 < a.size()) a[i * 2] = min(a[i * 2], a[i] + 1);
        if (i * 3 < a.size()) a[i * 3] = min(a[i * 3], a[i] + 1);
      }
      return a[n];
    }
};

int main(int argc, char *argv[]) {
  cout << Solution().minDays(10) << '\n';
  
  return 0;
}

