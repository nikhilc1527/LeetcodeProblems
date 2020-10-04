class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};

#include <queue>

class Solution {
public:
  Node* connect(Node* root) {
    if (!root) return root;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      auto size = q.size();
      
      for (int i = 0; i < size - 1; i++) {
        Node* cur = q.front();
        q.pop();
        cur->next = q.front();
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
      q.front()->next = nullptr;
      if (q.front()->left) q.push(q.front()->left);
      if (q.front()->right) q.push(q.front()->right);
      q.pop();
    }
    return root;
  }
};
