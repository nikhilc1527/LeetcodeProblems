#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    help(res, n, n, "");
    return res;
  }

  void help(std::vector<std::string> &res, int left, int right, std::string s) {
    if (left == 0 && right == 0) {
      res.push_back(s);
      return;
    }

    if (left > 0)
      help(res, left - 1, right, s + "(");

    if (right > left)
      help(res, left, right - 1, s + ")");
  }
};

class Solution2 {
public:
  std::vector<std::string> generateParenthesis(int n) {
    if (n == 1) return {"()"};
    else if (n == 2) return {"()()", "(())"};
    else {
      std::unordered_set<std::string> seen;
      std::vector<std::string> res;
      std::vector<std::string> prev = generateParenthesis(n - 1);

      for (std::string &str : prev) {
	std::string opt1 = "()" + str;
	std::string opt2 = "(" + str + ")";
	std::string opt3 = str + "()";

	if (!seen.count(opt1)) {
	  seen.insert(opt1);
	  res.push_back(opt1);
	}
	if (!seen.count(opt2)) {
	  seen.insert(opt2);
	  res.push_back(opt2);
	}
	if (!seen.count(opt3)) {
	  seen.insert(opt3);
	  res.push_back(opt3);
	}
      }

      return res;
    }
  }
};

