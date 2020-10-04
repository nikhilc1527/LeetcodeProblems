#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int unhappyFriends(int n, vector<vector<int>> &preferences,
                     vector<vector<int>> &ps) {
    vector<bool> unhappy(n, false);

    unordered_map<int, int> pairs;
    for (auto &i : ps) {
      pairs[i[0]] = i[1];
      pairs[i[1]] = i[0];
    }

    vector<unordered_map<int, int>> prefs(n);
    for (int j = 0; j < prefs.size(); j++) {
      auto &pref_list = preferences[j];
      for (int i = 0; i < pref_list.size(); i++) {
        prefs[j][pref_list[i]] = i;
      }
    }

    for (int x = 0; x < n; x++) {
      // if (unhappy[x]) continue;
      for (int u = x + 1; u < n; u++) {
        // if (unhappy[u]) continue;
        int y = pairs[x];
        int v = pairs[u];

        if (prefs[u][x] < prefs[u][v] && prefs[x][u] < prefs[x][y]) {
          unhappy[x] = true;
          unhappy[u] = true;
        }
      }
    }

    int res = 0;
    for (auto i : unhappy) res += i;

    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> prefs = {{1, 3, 2}, {2, 3, 0}, {1, 3, 0}, {0, 2, 1}};
  vector<vector<int>> pairs = {{1, 3}, {0, 2}};

  cout << s.unhappyFriends(4, prefs, pairs) << "\n";

  return 0;
}
