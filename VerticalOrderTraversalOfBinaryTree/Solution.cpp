#include <vector>
#include <algorithm>
#include <iostream>

#include "../Nodes.h"

class Solution {
public:
  int min(TreeNode* root, int i = 0) {
    int res = i;
    if (root->left) res = std::min(res, min(root->left, i - 1));
    if (root->right) res = std::min(res, min(root->right, i + 1));

    return res;
  }

  int max(TreeNode* root, int i = 0) {
    int res = i;
    if (root->left) res = std::max(res, max(root->left, i - 1));
    if (root->right) res = std::max(res, max(root->right, i + 1));

    return res;
  }

  void vertTraversal(std::vector<std::vector<std::pair<int, int>>> &res, int i, int j, TreeNode* root) {
    if (!root) return;
    res[i].push_back({root->val, j});
    vertTraversal(res, i - 1, j + 1, root->left);
    vertTraversal(res, i + 1, j + 1, root->right);
  }
  
  std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
    if (!root)
      return {};

    int min = this->min(root), max = this->max(root);

    std::vector<std::vector<std::pair<int, int>>> res(max - min + 1, std::vector<std::pair<int, int>>());
    vertTraversal(res, -min, 0, root);
    for (auto &i : res) {
      std::sort(i.begin(), i.end(), [](auto &i, auto &j) -> bool {
        if (i.second == j.second)
          return i.first < j.first;
        else
          return i.second < j.second;
      });
    }

    std::vector<std::vector<int>> realRes(max - min + 1, std::vector<int>());
    for (int i = 0; i < res.size(); i++) {
      for (int j = 0; j < res[i].size(); j++) {
        auto [val, y] = res[i][j];
        realRes[i].push_back(val);
      }
    }

    return realRes;
  }
};

int main(int argc, char *argv[]) {
  TreeNode* root = stringToTreeNode("[1,2,3,4,5,6,7]");

  auto res = Solution().verticalTraversal(root);

  for (auto &i : res) {
    for (auto j : i) {
      std::cout << j << ' ';
    }
    std::cout << '\n';
  }

  deleteTreeNode(root);
  
  return 0;
}
