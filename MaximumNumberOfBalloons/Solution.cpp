#include <iostream>
#include <string>
#include <array>

class Solution {
public:
  int maxNumberOfBalloons(std::string text) {
    std::array<int, 5> arr = {0};
    for (int i = 0; i < text.size(); i++) {
      switch(text[i]) {
      case 'b':
	arr[0]++;
	break;
      case 'a':
	arr[1]++;
	break;
      case 'l':
	arr[2]++;
	break;
      case 'o':
	arr[3]++;
	break;
      case 'n':
	arr[4]++;
	break;
      }
    }
    int min = arr[0];
    min = std::min(min, arr[1]);
    min = std::min(min, arr[2] / 2);
    min = std::min(min, arr[3] / 2);
    min = std::min(min, arr[4]);
    
    return min;
  }
};


int main(int argc, char *argv[]) {

  std::cout << Solution().maxNumberOfBalloons("nlaebolko") << "\n";
  std::cout << Solution().maxNumberOfBalloons("loonbalxballpoon") << "\n";

  return 0;
}
