#include <vector>
#include <string>
#include <unordered_set>
#include <string_view>

class Solution {
public:
  std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    if(s.length()<10) return {};
    std::unordered_set<std::string_view> uset;
    std::unordered_set<std::string> res;
    for(int i=0; i<=s.length()-10; i++){
      if(uset.count({s.data()+i, 10}))
        res.insert(s.substr(i, 10));
      else
        uset.insert({s.data()+i,10});
    }
        
    return {res.begin(), res.end()};
  }
};
