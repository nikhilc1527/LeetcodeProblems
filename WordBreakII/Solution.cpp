#include <vector>
#include <string>
#include <unordered_set>
#include <string_view>
#include <iostream>
#include <unordered_map>

class Solution {
public:
  using ret_type = std::vector<std::string>;
    
  ret_type find(std::unordered_map<int, std::vector<std::string>> &memo, std::unordered_set<std::string_view> &words, std::string_view s_orig, int idx) {
    if (idx >= s_orig.size())
      return {};
    
    if (memo.count(idx)) {
      return memo[idx];
    }
    ret_type res;
    auto s1 = s_orig.substr(idx, s_orig.size());
    if (words.count(s1))
      res.push_back(std::string(s1));
    
    for (int i = 0; idx + i < s_orig.size(); i++) {
      auto s2 = s_orig.substr(idx, i);
      if (words.count(s2)) {
        auto res2 = find(memo, words, s_orig, idx + i);
        for (auto &j : res2) {
          res.push_back(std::string(s2) + " " + j);
        }
      }
    }

    memo[idx] = res;
    return memo[idx];
  }
  
  std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string_view> words;
    for (auto &i : wordDict) {
      words.insert(i);
    }

    std::unordered_map<int, std::vector<std::string>> memo;

    return find(memo, words, s, 0);
  }
};

int main() {
  Solution s;
  // std::string input = "catsanddog";
  // std::vector<std::string> wordDict = {"cat", "cats", "and", "sand", "dog"};
  // auto res = s.wordBreak(input, wordDict);
  // for (auto i : res) {
  //   std::cout << i << std::endl;
  // }

  std::string input = "aaaabaaaa";
  std::vector<std::string> wordDict =
  { "a",
    "aa",
    "aaa",
    "aaaa",
    "aaaaa",
    "aaaaaa",
    "aaaaaaa",
    "aaaaaaaa",
    "aaaaaaaaa",
    "aaaaaaaaaa" };

  auto res = s.wordBreak(input, wordDict);
  for (auto i : res) {
    std::cout << i << std::endl;
  }

  return 0;
}
