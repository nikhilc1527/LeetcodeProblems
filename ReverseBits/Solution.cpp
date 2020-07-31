#include <iostream>

class Solution {
public:
  unsigned int reverseBits(unsigned int n) {
    unsigned int res = 0;
    for (int i = 0; i < 32; i++) {
      res <<= 1;
      res |= (n & 1);
      n >>= 1;
    }
    return res;
  }
};

int main() {
  unsigned int n = 43261596;
  unsigned int res = Solution().reverseBits(n);
  std::cout << res << std::endl;
}
