#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
#include <list>
#include <stack>
#include <unordered_map>

class Solution {
public:
  double average(std::vector<int> &salary) {
    int min = salary[0], max = salary[salary.size() - 1];
    double sum = 0;
    for (int i = 0; i < salary.size(); i++) {
      max = std::max(max, salary[i]);
      min = std::min(min, salary[i]);
    }

    for (int i = 0; i < salary.size(); i++) {
      if (salary[i] > min && salary[i] < max)
	sum += salary[i];
    }
	
    return sum / (salary.size() - 2);
  }

  int kthFactor(int n, int k) {
    int i, j;
    for (i = 1, j = 1; j <= k && i <= n; i++) {
      if (n % i == 0) {
	if (j == k) return i;
	else j++;
      }
    }
    return -1;
  }

  int longestSubarray(std::vector<int> &nums) {
    int i = 0, j = 0;
    while (j < nums.size() && nums[j]) j++;
    if (j == nums.size()) return nums.size() - 1;
    int maxLen = 0;
    std::queue<int> q;
    q.push(j);
    j++;
    while (j < nums.size()) {
      while (j < nums.size() && nums[j]) j++;
      if (j < nums.size())
	maxLen = std::max(maxLen, j - i - 1);
      else
	maxLen = std::max(maxLen, static_cast<int>(nums.size()) - 1 - i);
      q.push(j);
      i = q.front() + 1;
      q.pop();
      j++;
    }

    return maxLen;
  }
  
  int minNumberOfSemesters(int n, std::vector<std::vector<int>>& dep, int k) {
    int f[1<<15];
    const int INF = 1000000000;
        
    std::vector<std::vector<int>> v(n);
    for (auto e : dep)
      {
	v[e[1]-1].push_back(e[0]-1);
      }
        
    for (int s = 0; s < 1<<n; ++s) f[s] = INF;
    f[0] = 0;
        
    for (int s = 0; s < 1<<n; ++s)
      {
	if (f[s] == INF) continue;
            
	int can = 0;
	for (int i = 0; i < n; ++i)
	  {
	    if (s>>i&1) continue;
	    int flag = 0;
	    for (auto j : v[i])
	      {
		if (!(s>>j&1)) flag = 1;
	      }
	    if (flag == 0) can |= 1<<i;
	  }
            
	for (int t = can; t; t = (t-1)&can)
	  {
	    if (__builtin_popcount(t) > k) continue;
	    f[s|t] = std::min(f[s|t], f[s]+1);
                
	  }
      }
        
    return f[(1<<n)-1];
  }
};

int main() {
  Solution s;
  int n = 4;
  std::vector<std::vector<int>> dep = {{2, 1}, {3, 1}, {1, 4}};
  int k = 2;
  std::cout << s.minNumberOfSemesters(n, dep, k) << std::endl;
}
