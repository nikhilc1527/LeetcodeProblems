#include <vector>

class Solution {
public:
  int minDays(std::vector<int> bloomDay, int m, int k) {
    int n = bloomDay.size();
        
    if(n < m * k) return -1;
        
    int minDay = (int) 1e9, maxDay = 1;
        
    for(int day : bloomDay) {
      minDay = std::min(minDay, day);
      maxDay = std::max(maxDay, day);
    }
        
    while(minDay < maxDay) {
      int mid = minDay + (maxDay - minDay) / 2;
      if(hasBouquets(bloomDay, m, k, mid)) 
	maxDay = mid;
      else minDay = mid + 1;
    }
    return minDay;
  }

  bool hasBouquets(std::vector<int> bloomDay, int m, int k, int day) {
    int left = bloomDay.size(), flowers = 0;
        
    for(int i = 0; i < bloomDay.size(); i++) {
      int d = bloomDay[i];
      left--;
            
      if(d <= day) {
	flowers++;
      } 
      else {
	m -= flowers / k;
                
	if(m <= 0) 
	  return true;
                
	if(left < m * k) 
	  return false;
                
	flowers = 0;
      }
    }
    return flowers / k >= m;
  }
};
