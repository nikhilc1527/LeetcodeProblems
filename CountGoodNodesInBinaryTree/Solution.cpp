#include "../Nodes.h"

class Solution {
public:
  void goodNodes(TreeNode* root, int &num, int max) {
    if (!root) return;
    if (max <= root->val) num++;
    max = std::max(max, root->val);
    goodNodes(root->left, num, max);
    goodNodes(root->right, num, max);
  }
  
  int goodNodes(TreeNode* root) {
    int num = 0;
    goodNodes(root, num, root->val);
    return num;
  }
};
