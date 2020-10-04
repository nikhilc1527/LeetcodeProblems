#include <vector>
#include <bitset>
#include <iostream>

int main(int argc, char *argv[]) {
  std::vector<std::bitset<15>> bits;
  bits.push_back(std::bitset<15>("11100"));
  bits.push_back(std::bitset<15>("11010"));
  bits.push_back(std::bitset<15>("11001"));
  bits.push_back(std::bitset<15>("10110"));
  bits.push_back(std::bitset<15>("10101"));
  bits.push_back(std::bitset<15>("10011"));
  bits.push_back(std::bitset<15>("01110"));
  bits.push_back(std::bitset<15>("01101"));
  bits.push_back(std::bitset<15>("01011"));
  bits.push_back(std::bitset<15>("00111"));

  std::cout << bits.size() << '\n' << '\n';

  for (auto &i : bits) {
    std::cout << i.to_ullong() << '\n';
  }
  
  return 0;
}
