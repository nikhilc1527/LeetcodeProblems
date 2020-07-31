#include "../Nodes.h"
#include <iostream>

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
      int res = 0;
      if (!root) return res;
      if (root->val % 2 == 0) {
	if (root->left) {
	  if (root->left->left) res += root->left->left->val;
	  if (root->left->right) res += root->left->right->val;
	}
	if (root->right) {
	  if (root->right->left) res += root->right->left->val;
	  if (root->right->right) res += root->right->right->val;
	}
      }

      std::cout << "Hello world" << "\n";
      std::cout << "Hello world" << "\n";

      return res + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
    }
};
