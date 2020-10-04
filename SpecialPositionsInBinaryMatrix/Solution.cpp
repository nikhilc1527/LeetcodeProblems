#include <vector>

class Solution {
 public:
  int numSpecial(std::vector<std::vector<int>>& mat) {
    int res = 0;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[i].size(); j++) {
        if (mat[i][j] != 1) continue;
        bool gud = true;
        for (int i2 = 0; i2 < mat.size(); i2++) {
          if (i2 == i) continue;
          if (mat[i2][j]) {
            gud = false;
            break;
          }
        }
        if (!gud) continue;
        for (int j2 = 0; j2 < mat[i].size(); j2++) {
          if (j2 == j) continue;
          if (mat[i][j2]) {
            gud = false;
            break;
          }
        }
        if (!gud) continue;
        res++;
      }
    }
    return res;
  }
};
