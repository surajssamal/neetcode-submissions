/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
  int n = 0;
  while (curr && n < k) {
    curr = curr->next;
    n++;
  }
  if (n == k) {
    curr = reverseKGroup(curr, k);
    ListNode *next_ptr = nullptr;
    while (n-- > 0) {
      next_ptr = head->next;
      head->next = curr;
      curr = head;
      head = next_ptr;
    }
    head = curr;
  }
  return head;
    }
};
