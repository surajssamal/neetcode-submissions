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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode *curr = head;
  vector<ListNode *> values;
  while (curr) {
    values.push_back(curr);
    curr = curr->next;
  }
  n = values.size() - n;
  if (n == 0) {
    return head->next;
  }
  values[n - 1]->next = values[n]->next;

  return head;
    }
};
