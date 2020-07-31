#include <vector>

class Solution {
public:
  int minFlips(int a, int b, int c) {
    int res = 0;
    
    for (int i = 0; i < 32; i++) {
      if (a == 0 && b == 0 && c == 0) break;
      int abit = a & 1, bbit = b & 1, cbit = c & 1;
      if (!cbit)
	res += abit + bbit;
      else res += !abit && !bbit;
      a >>= 1;
      b >>= 1;
      c >>= 1;
    }

    return res;
  }
};
