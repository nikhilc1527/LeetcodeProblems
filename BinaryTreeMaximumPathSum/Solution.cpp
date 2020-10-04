#include "../Nodes.h"

class Solution {
public:
  std::vector<int> values;
  std::vector<std::vector<int>> connections;

  void convert(TreeNode* root, int &i) {
    if (!root) return;

    values.push_back(root->val);
    root->val = i++;
    
    convert(root->left, i);
    convert(root->right, i);
  }

  void makeAdjLists(TreeNode* root) {
    if (!root) return;
    if (root->left) {
      connections[root->val].push_back(root->left->val);
      connections[root->left->val].push_back(root->val);
    }
    if (root->right) {
      connections[root->val].push_back(root->right->val);
      connections[root->right->val].push_back(root->val);
    }
  }
  
  int maxPathSum(TreeNode* root) {
    int i = 0;
    convert(root, i);
    std::cout << tr << "\n";

  }
};
