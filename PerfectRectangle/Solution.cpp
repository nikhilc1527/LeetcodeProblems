#include <vector>
#include <iostream>
#include <climits>
#include <set>
#include <utility>

class Solution {
public:
  bool isRectangleCover(std::vector<std::vector<int>>& rectangles) {
    std::set<std::pair<int,int>> Set;
    int area=0;
    for(auto& x:rectangles)
      {
        std::pair<int,int> p1{x[0],x[1]};
        std::pair<int,int> p2{x[2],x[3]};
        std::pair<int,int> p3{x[0],x[3]};
        std::pair<int,int> p4{x[2],x[1]};

        area+=(x[2]-x[0])*(x[3]-x[1]);

        if(Set.count(p1)) {
          Set.erase(p1);
        }
        else {
          Set.insert(p1);
        }


        if(Set.count(p2)) {
          Set.erase(p2);
        }
        else {
          Set.insert(p2);
        }

        if(Set.count(p3)) {
          Set.erase(p3);
        }
        else {
          Set.insert(p3);
        }


        if(Set.count(p4)) {
          Set.erase(p4);
        }
        else {
          Set.insert(p4);
        }
      }
    return Set.size()==4 && area==((*Set.rbegin()).second-(*Set.begin()).second)*((*Set.rbegin()).first-(*Set.begin()).first);
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> rects = {{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
  Solution s;
  std::cout << std::boolalpha << s.isRectangleCover(rects) << '\n';
  
  return 0;
}
