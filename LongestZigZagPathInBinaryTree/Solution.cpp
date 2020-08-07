#include <iostream>

#include "../Nodes.h"

class Solution {
public:
  int longestZigZag(TreeNode* root) {
    if (root == nullptr) return 0;
    int max_length = 0;
    dfs(root, 0, 0, max_length);
    dfs(root, 1, 0, max_length);
    return max_length;
  }

  void dfs(TreeNode *root, int direction, int curr_length, int &max_length) {
    if (root == nullptr) return;
    if (direction == 0) {
      if (!root->left) {
        max_length = std::max(curr_length, max_length);
      } else {
        dfs(root->left, 1 - direction, curr_length + 1, max_length);
      }
      if (root->right) dfs(root->right, 0, 1, max_length);
    } else {
      if (!root->right) {
        max_length = std::max(curr_length, max_length);
      } else {
        dfs(root->right, 1 - direction, curr_length + 1, max_length);
      }
      if (root->left) dfs(root->left, 1, 1, max_length);
    }
  }
};

int main(int argc, char *argv[]) {
  TreeNode* root = stringToTreeNode("[1, 2, 3, null, 5]");

  std::cout << Solution().longestZigZag(root) << '\n';

  deleteTreeNode(root);
  return 0;
}

