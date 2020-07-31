#include <vector>
#include <array>
#include <iostream>

class Solution {
public:
  int leastInterval(std::vector<char>& tasks, int n) {
    std::array<int, 26> freqs {0};
    for (auto i : tasks) {
      freqs[i - 'A']++;
    }

    int max_count = -1;
    for(auto i : freqs) {
      max_count = std::max(max_count, i);
    }

    int num_occ = 0;
    for (auto i : freqs) {
      if (i == max_count) num_occ++;
    }

    return std::max((int)tasks.size(), (max_count - 1) * (n + 1) + num_occ);
  }
};

int main(int argc, char *argv[]) {
  std::vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  tasks = {'A', 'B', 'C', 'A', 'B', 'C'};

  std::cout << Solution().leastInterval(tasks, 2) << '\n';
  
  return 0;
}

/*
  ["A", "A", "A", "A"]
3
["A","A","A","B","B","B"] 
3 
["A","A","A","B","B","B", "A", "A"] 
2 
["A","A","A","B","B","B"] 
0 
["A","A","A","A","A","A","B","C","D","E","F","G","B", "C", "D", "D", "E", "B"] 
2 
["A","A","A","A","A","A","B","C","D","E","F","G"] 
2
["A", "B", "C", "A", "B", "C"]
3
 */
