#include <vector>
#include <cstring>
#include <iostream>

class Solution {
public:
  bool canMakeArithmeticProgression(std::vector<int>& arr) {
    if (arr.size() <= 1) return true;

    int min = 1e6, max = -1e6;
    for (auto &i : arr) {
      if (i < min) min = i;
      if (i > max) max = i;
    }

    if (min == max) return true;

    int size = max - min + 1;
    int freqs[size];
    memset(&freqs, 0, (size) * sizeof(int));

    for (auto &i : arr) {
      freqs[i - min]++;
    }

    int m = 0;
    for (int i = 1; i < size; i++) {
      if (freqs[i]) {
	m = i;
	break;
      }
    }

    for (int i = 0; i < size; i++) {
      if (freqs[i] > 1) return false;
      if (i % m == 0 && !freqs[i]) return false;
      else if (i % m != 0 && freqs[i]) return false;
    }

    return true;
  }
};

int main() {
  std::vector<int> arr = {3, 5, 1};
  const bool &res = Solution().canMakeArithmeticProgression(arr);
  std::cout << std::boolalpha << res << std::endl;
}
