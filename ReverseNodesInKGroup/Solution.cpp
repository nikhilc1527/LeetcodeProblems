#include <iostream>

#include "../Nodes.h"

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;
    ListNode tempHead(0, head);
    ListNode *begin = &tempHead, *prev, *cur, *next, *end = begin->next;
    while (true) {
      int i = 0;
      for (i = 0; i < k; i++) {
	if (!end) break;
	else end = end->next;
      }
      if (i < k) break;
      prev = begin->next;
      cur = prev->next;
      next = cur->next;
      while (next != end) {
	cur->next = prev;
	prev = cur;
	cur = next;
	next = cur->next;
      }
      cur->next = prev;
      ListNode *newBegin = begin->next;
      begin->next->next = end;
      begin->next = cur;

      begin = newBegin;
    }

    return tempHead.next;
  }
};

int main() {
  Solution s;
  ListNode *head = stringToListNode("[5, 3, 4, 2, 6, 1]");
  ListNode *res = s.reverseKGroup(head, 4);
  std::cout << listNodeToString(res) << std::endl;
}
