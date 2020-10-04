#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <iostream>
#include <algorithm>

class CombinationIterator {
private:
  
  int i;
  std::vector<std::string> strs;

  std::string getString(std::bitset<15> bits, const std::string &str) {
    std::string res;
    for (int j = 0; j < bits.size(); j++) {
      if (bits[j]) {
        res.push_back(str[j]);
      }
    }
    return res;
  }
  
public:
  CombinationIterator(const std::string &str, int len) : i(0), strs() {
    for (int j = 0; j < std::pow(2, str.size()); j++) {
      std::bitset<15> bits(j);
      if (bits.count() == len) {
        strs.push_back(getString(bits, str));
      }
    }

    std::sort(strs.begin(), strs.end());
  }
  
  std::string next() {
    return strs[i++];
  }
    
  bool hasNext() {
    return i < strs.size();
  }
};

int main(int argc, char *argv[]) {
  
  CombinationIterator it("bvwz", 2);
  while (it.hasNext()) {
    std::cout << it.next() << "\n";
  }
  
  return 0;
}
