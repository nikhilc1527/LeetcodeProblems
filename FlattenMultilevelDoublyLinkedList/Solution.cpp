#include <utility>

class Node {
public:
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

class Solution {
public:
  std::pair<Node*, Node*> flattenLevel(Node* head) {
    Node* dummy = head;
    while (dummy->next) {
      if (dummy->child) {
	std::pair<Node*, Node*> childLevel = flattenLevel(dummy->child);
	Node* end = dummy->next;
	
	childLevel.second->next = end;
        end->prev = childLevel.second;
	
	dummy->next = childLevel.first;
        dummy->next->prev = dummy;

	dummy->child = nullptr;
	
	dummy = end->prev;
      }
      dummy = dummy->next;
    }
    if (dummy->child) {
      std::pair<Node*, Node*> childLevel = flattenLevel(dummy->child);

      childLevel.second->next = nullptr;
      
      dummy->next = childLevel.first;
      dummy->next->prev = dummy;

      dummy->child = nullptr;
      
      dummy = childLevel.second;
    }
    return {head, dummy};
  }
  
  Node* flatten(Node* head) {
    if (!head) return nullptr;
    return flattenLevel(head).first;
  }
};

int main() {
  Node head = {1, nullptr, nullptr, nullptr};
  Node n2 = {2, nullptr, nullptr, nullptr};
  Node n3 = {3, nullptr, nullptr, nullptr};
  Node n4 = {4, nullptr, nullptr, nullptr};
  Node n5 = {5, nullptr, nullptr, nullptr};
  Node n6 = {6, nullptr, nullptr, nullptr};
  Node n7 = {7, nullptr, nullptr, nullptr};
  Node n8 = {8, nullptr, nullptr, nullptr};
  Node n9 = {9, nullptr, nullptr, nullptr};
  Node n10 = {10, nullptr, nullptr, nullptr};
  Node n11 = {11, nullptr, nullptr, nullptr};
  Node n12 = {12, nullptr, nullptr, nullptr};
  head.next = &n2;
  n2.prev = &head;
  n2.next = &n3;
  n3.prev = &n2;
  n3.next = &n4;
  n4.next = &n5;
  n4.prev = &n3;
  n5.next = &n6;
  n5.prev = &n4;
  n6.prev = &n5;
  n3.child = &n7;
  n7.next = &n8;
  n8.prev = &n7;
  n8.next = &n9;
  n9.prev = &n8;
  n9.next = &n10;
  n10.prev = &n9;
  n8.child = &n11;
  n11.next = &n12;
  n12.prev = &n11;

  Node* flattened = Solution().flatten(&head);
  return 0;
}
