#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double pi = 2 * acos(0.0);
  int visiblePoints(vector<vector<int>>& points, int angle2,
                    vector<int>& location) {
    double angle = angle2 * pi / 180.0;
    auto ang = [&](auto& pt) {
      return std::atan2(pt[1] - location[1], pt[0] - location[0]);
    };

    int num = 0;
    for (int i = 0; i < points.size(); ++i) {
      if (points[i] == location) {
        points.erase(points.begin() + i--);
        ++num;
      }
    }
    vector<double> pts;
    for (auto i : points) pts.push_back(ang(i));
    sort(pts.begin(), pts.end());

    for (int i = 0, sz = pts.size(); i < sz; ++i)
      pts.push_back(pts[i] + 2 * pi);

    int max = -1;

    int j = 0;
    for (int i = 0; i < pts.size() && j < pts.size(); ++i) {
      while (j < pts.size() && pts[j] <= pts[i] + angle) ++j;
      --j;
      max = std::max(max, j - i);
    }
    return max + 1 + num;
  }
};

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> points{{1, 1}, {2, 2}, {3, 3},
                                       {4, 4}, {1, 2}, {2, 1}};
  /*
  [[1,1],[2,2],[3,3],[4,4],[1,2],[2,1]]
  0
  [1,1]
   */
  double ang = 0;
  std::vector<int> loc{1, 1};

  auto res = Solution().visiblePoints(points, ang, loc);
  cout << res << "\n";

  return 0;
}
