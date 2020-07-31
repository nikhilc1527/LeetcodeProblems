#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <deque>

#include "../Nodes.h"

class Solution {
public:
  bool isSubPath(ListNode* head, TreeNode* root) {
    /*
     * TLE
    if (!head && !root) return true;
    if (!head || !root) return false;

    if (head->val == root->val) {
      if (!head->next) return true;
      else return isSubPath(head->next, root->left) || isSubPath(head->next, root->right) || isSubPath(head->next, root->left) || isSubPath(head->next, root->right);
    }
    else return isSubPath(head, root->left) || isSubPath(head, root->right);;
    */

    /*
     * Some wierd memory leak
    std::deque<std::pair<ListNode*, TreeNode*>> q;
    q.push_back({head, root});
    while (!q.empty()) {
      auto& [ln, rt] = q.front();
      q.pop_front();
      if (!ln) {
	while (!q.empty()) q.pop_front();
	return true;
      }
      else if (!rt) continue;
      else {
	if (ln->val == rt->val) {
	  q.push_back({ln->next, rt->left});
	  q.push_back({ln->next, rt->right});
	}

	q.push_back({head, rt->left});
	q.push_back({head, rt->right});
      }
    }

    return false;
    */

    if(!head)
      return true;
    if(!root)
      return false;

    return dfs(head,root) || isSubPath(head,root->left) ||isSubPath(head,root->right);
  }

  bool dfs(ListNode *head, TreeNode *root){
    if(!head)
      return true;
    if(!root)
      return false;
    if(root->val != head->val)
      return false;
    return dfs(head->next,root->left) || dfs(head->next,root->right);
  }
};

int main() {
  ListNode* head = stringToListNode("[4,2,8]");
  TreeNode* root = stringToTreeNode("[1,4,4,2,null,2,null,1,null,6,8]");
  std::cout << std::boolalpha << Solution().isSubPath(head, root) << std::endl;
  delete head;
  delete root;
}
