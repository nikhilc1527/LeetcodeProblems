#include <initializer_list>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void trimLeftTrailingSpaces(std::string &input) {
  input.erase(input.begin(), std::find_if(input.begin(), input.end(), [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(std::string &input) {
  input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(), input.end());
}

std::vector<int> stringToIntegerVector(std::string input) {
  std::vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  std::stringstream ss;
  ss.str(input);
  std::string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

ListNode* stringToListNode(std::string input) {
  // Generate list from the input
  std::vector<int> list = stringToIntegerVector(input);

  // Now convert that list into linked list
  ListNode* dummyRoot = new ListNode(0);
  ListNode* ptr = dummyRoot;
  for(int item : list) {
    ptr->next = new ListNode(item);
    ptr = ptr->next;
  }
  ptr = dummyRoot->next;
  delete dummyRoot;
  return ptr;
}

int stringToInteger(std::string input) {
  return std::stoi(input);
}

std::string listNodeToString(ListNode* node) {
  if (node == nullptr) {
    return "[]";
  }

  std::string result;
  while (node) {
    result += std::to_string(node->val) + ", ";
    node = node->next;
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

void deleteListNode(ListNode* head) {
  while (head) {
    ListNode* next = head->next;
    delete head;
    head = next;
  }
}


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* stringToTreeNode(std::string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  if (!input.size()) {
    return nullptr;
  }

  std::string item;
  std::stringstream ss;
  ss.str(input);

  getline(ss, item, ',');
  TreeNode* root = new TreeNode(stoi(item));
  std::queue<TreeNode*> nodeQueue;
  nodeQueue.push(root);

  while (true) {
    TreeNode* node = nodeQueue.front();
    nodeQueue.pop();

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int leftNumber = stoi(item);
      node->left = new TreeNode(leftNumber);
      nodeQueue.push(node->left);
    }

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int rightNumber = stoi(item);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}

void deleteTreeNode(TreeNode* root) {
  if (!root) return;
  deleteTreeNode(root->left);
  deleteTreeNode(root->right);
  delete root;
}
