#include <vector>
#include <map>
#include <unordered_map>

#include "../Nodes.h"

class Solution {
public:
  std::unordered_map<int, int> in_ind;

  TreeNode* generate(std::vector<int>& inorder, std::vector<int>& postorder, int ii, int ij, int pi, int pj) {
    if (ii > ij || pi > pj) return nullptr;
    int val = postorder[pj];
    TreeNode* root = new TreeNode(val);

    int i = in_ind[val];

    int left_subtree_size = i - ii;
    int right_subtree_size = ij - i;

    int leftpj = pi + left_subtree_size - 1;
    root->left = generate(inorder, postorder, ii, i - 1, pi, leftpj);

    int rightpi = pj - (right_subtree_size);
    int rightpj = pj - 1;
    root->right = generate(inorder, postorder, i + 1, ij, rightpi, rightpj);

    return root;
  }
  
  TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    if (!inorder.size() || !postorder.size()) return nullptr;
    
    for (int i = 0; i < inorder.size(); i++) {
      in_ind[inorder[i]] = i;
    }

    return generate(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode* res;
  
  std::vector<int> inorder = {9,3,15,20,7};
  std::vector<int> postorder = {9,15,7,20,3};

  // res = s.buildTree(inorder, postorder);

  // inorder = {3, 2, 1};
  // postorder = {3, 2, 1};

  // s = Solution();

  // res = s.buildTree(inorder, postorder);
  
  inorder = {1, 2, 3};
  postorder = {3, 2, 1};

  s = Solution();

  res = s.buildTree(inorder, postorder);
  
  return 0;
}
