#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <tuple>
#include <iostream>

#include "../Nodes.h"

class Solution {
public:
  int getHeight(TreeNode* root) {
    if (!root) return 0;
    else return 1 + std::max(getHeight(root->left), getHeight(root->right));
  }

  using res_type = std::vector<std::vector<std::string>>;
  void printTree(TreeNode* root, res_type &res, int col, int i, int j) {
    if (!root) return;
    res[col][(i + j) / 2] = std::to_string(root->val);
    printTree(root->left, res, col + 1, i, (i + j) / 2);
    printTree(root->right, res, col + 1, (i + j + 1) / 2, j);
  }
  
  res_type printTree(TreeNode* root) {
    int height = getHeight(root);
    int width = (1 << height) - 1;
    res_type res(height, std::vector<std::string>(width, ""));

    printTree(root, res, 0, 0, width);

    return res;
  }
};

void test(std::string input) {
  TreeNode* root = stringToTreeNode(input);
  Solution s;

  auto res = s.printTree(root);
  for (auto i : res) {
    for (auto j : i) {
      std::cout << j << '.';
    }
    std::cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  test("[1,2,null,null,3,4,null,5,null,6,null]");
  test("[0,2,4,1,null,3,-1,5,1,null,6,null,8]");
  
  return 0;
}
