#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  using map = std::unordered_map<int, int>;
  using set = std::unordered_set<int>;

  int find(map& uf, int i) {
    if (!uf.count(i)) uf[i] = i;
    if (uf[i] != i) uf[i] = find(uf, uf[i]);
    return uf[i];
  }
  void unite(map& uf, int a, int b) {
    a = find(uf, a);
    b = find(uf, b);
    if (a != b) uf[a] = b;
  }
  int longestConsecutive(std::vector<int>& nums) {
    map uf;
    set seen;

    for (auto i : nums) {
      if (seen.count(i)) continue;
      seen.insert(i);
      if (seen.count(i - 1)) unite(uf, i - 1, i);
      if (seen.count(i + 1)) unite(uf, i + 1, i);
    }

    map bigly;
    for (auto i : seen) {
      ++bigly[find(uf, i)];
    }

    int max = 0;
    for (auto i : bigly) {
      max = std::max(max, i.second);
    }
    return max;
  }
};

int main(int argc, char* argv[]) {
  // std::vector<int> nums{9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
  std::vector<int> nums{1, 3};
  int res = Solution().longestConsecutive(nums);

  std::cout << res << "\n";

  return 0;
}
