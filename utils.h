#include <vector>
#include <iostream>

namespace utils {
  
  void print_2d_vector(std::vector<std::vector<int>> values) {
    std::cout << "[" << std::endl;
    for (std::size_t i = 0; i < values.size(); i++) {
      std::cout << "  ";
      if (values[i].size() > 0) std::cout << values[i][0];
      for (std::size_t j = 1; j < values[i].size(); j++) {
	std::cout << ", " << values[i][j];
      }

      std::cout << std::endl;
    }

    std::cout << "]" << std::endl;
  }
  
}
