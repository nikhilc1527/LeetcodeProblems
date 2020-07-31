#include <deque>
#include <iostream>
#include <climits>
#include <cmath>
#include <limits>

#include "../Nodes.h"

class Solution {
public:
  /*
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    std::deque<TreeNode*> curLevel, nextLevel;
    curLevel.push_back(root);
    int maxWidth = -1;

    while (!curLevel.empty()) {
      while (!curLevel.front()) curLevel.pop_front();
      while (!curLevel.back()) curLevel.pop_back();
      maxWidth = std::max(maxWidth, static_cast<int>(curLevel.size()));
      nextLevel = std::deque<TreeNode*>();
      bool cont = false;
      while (!curLevel.empty()) {
	if (curLevel.front()) {
	  nextLevel.push_back(curLevel.front()->left);
	  
	  if (nextLevel.back())
	    cont = true;

	  nextLevel.push_back(curLevel.front()->right);
	  if (nextLevel.back())
	    cont = true;
	}
	else {
	  nextLevel.push_back(nullptr);
	  nextLevel.push_back(nullptr);
	}
	curLevel.pop_front();
      }
      if (!cont) return maxWidth;
      curLevel = nextLevel;
    }

    return maxWidth;
  }
  */

  /*
    void widthOfBinaryTree(TreeNode* root, std::vector<std::pair<long double, long double>> &maxes, int &maxWidth, const long double &ind, const long double &level) {
    if (!root) return;

    if (maxes.size() < level)
    maxes.push_back({std::numeric_limits<long double>::max(), std::numeric_limits<long double>::min()});

    maxes[level - 1].first = std::min(maxes[level - 1].first, ind);
    maxes[level - 1].second = std::max(maxes[level - 1].second, ind);

    maxWidth = std::max(maxWidth, static_cast<int>(maxes[level - 1].second - maxes[level - 1].first + 1));

    widthOfBinaryTree(root->left, maxes, maxWidth, ind * 2, level + 1);
    widthOfBinaryTree(root->right, maxes, maxWidth, (ind * 2) + 1, level + 1);
    }
  
    int widthOfBinaryTree(TreeNode* root) {
    std::vector<std::pair<long double, long double>> maxes;
    int maxWidth = 0;
    widthOfBinaryTree(root, maxes, maxWidth, 1, 1);
    return static_cast<int>(maxWidth);
      
    return 0;
    }
  */

  int widthOfBinaryTree(TreeNode* root) {
    int maxwidth = 0;
    std::vector<std::pair<TreeNode*,  int>> q;
        
    if (root == NULL)
      return 0;

    q.push_back(std::make_pair(root, 1)); //Push the root in current queue

    while (q.size()) { //While current queue is not empty
      std::vector<std::pair<TreeNode*,  int>> nextlev; //The queue/vector for next level nodes
      int currentwidth;
            
      currentwidth = (q.back().second - q.front().second) + 1;
      maxwidth = std::max(currentwidth, maxwidth);

      for (int i = 0; i < q.size(); i++) { //For each node in current queue, add their children in nextlev queue
	if (q[i].first->left) {
	  nextlev.push_back(std::make_pair(q[i].first->left, ((long) q[i].second * 2)));
	}
	if (q[i].first->right) {
	  nextlev.push_back(std::make_pair(q[i].first->right, ((long) q[i].second * 2) + 1));
	}
      }
      
      q = nextlev;
    }

    return maxwidth;
  }
};

int main() {
  /*
    Solution s;
    TreeNode* root = stringToTreeNode("[1,3,2,5,null,null,9,6,null,null,7]");
    int res = s.widthOfBinaryTree(root);
    std::cout << res << std::endl;
    root = stringToTreeNode("[1,3,2,5,3,null,9]");
    res = s.widthOfBinaryTree(root);
    std::cout << res << std::endl;
    root = stringToTreeNode("[1,3,null,5,3]");
    res = s.widthOfBinaryTree(root);
    std::cout << res << std::endl;
  */

  for (double i = 1;; i *= 10) {
    std::cout << i << std::endl;
  }
  
  long double PI = std::acos(-1.0L);
  std::cout << PI << std::endl;
  std::cout << sizeof(long double) << std::endl;

  std::cout << std::numeric_limits<long double>::digits10 << std::endl;
}
