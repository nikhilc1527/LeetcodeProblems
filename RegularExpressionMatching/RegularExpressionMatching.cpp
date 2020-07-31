// #10. Regular Expression Matching: Hard
#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
  bool isMatch(std::string s, std::string p) {
    int s_size=s.size();
    int p_size=p.size();
    std::vector<std::vector<int>> DP(s_size+1,std::vector<int>(p_size+1,0));
    DP[0][0]=1;
    for(int j(2);j<=DP[0].size()-1;j++) {
      if(DP[0][j-2]&&p[j-1]=='*') {
	DP[0][j]=1;
      }
    }
    for(int i = 1; i < DP.size(); i++) {
      for(int j = 1; j < DP[0].size(); j++) {
	if(p[j-1] == '*') {
	  DP[i][j] = DP[i][j-2];
	  if(p[j-2] == '.' || p[j-2] == s[i-1]) {
	    if(DP[i-1][j]) {
	      DP[i][j]=1;
	    }
	  }
	}
	else if(p[j-1] == s[i-1] || p[j-1] == '.') {
	  DP[i][j] = DP[i-1][j-1];
	}
      }
    }
    return DP[s_size][p_size]==1;
  }
};

#ifdef DEBUG
int main() {
  Solution s;
  std::string expr = "aab";
  std::string regex = "c*a*b";
  bool res = s.isMatch(expr, regex);
  std::cout << std::boolalpha << res << std::endl;
}
#endif
