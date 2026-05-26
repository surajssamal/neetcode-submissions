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
    ListNode* mergeTwoLists(ListNode* inp1, ListNode* inp2) {
          if (inp1 == nullptr) {
    return inp2;
  }
  if (inp2 == nullptr) {
    return inp1;
  }
ListNode *l = inp1;
  ListNode *r = inp2;
  ListNode *result;
  if (l->val < r->val) {
    result = new ListNode(l->val);
    l = l->next;
  } else {
    result = new ListNode(r->val);
    r = r->next;
  }
  ListNode *current = result;

  while (l && r) {
    if (l->val <= r->val) {
      ListNode *temp = new ListNode(l->val);
      l = l->next;
      current->next = temp;
      current = temp;
    } else {
      ListNode *temp = new ListNode(r->val);
      r = r->next;
      current->next = temp;
      current = temp;
    }
  }
  while (l) {
    ListNode *temp = new ListNode(l->val);
    l = l->next;
    current->next = temp;
    current = temp;
  }
  while (r) {
    ListNode *temp = new ListNode(r->val);
    r = r->next;
    current->next = temp;
    current = temp;
  }

  return result;
    }
};
