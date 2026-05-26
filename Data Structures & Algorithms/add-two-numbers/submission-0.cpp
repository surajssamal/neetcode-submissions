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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          ListNode *result = new ListNode();
  ListNode *curr = result;
  int carry = 0;
  while (l1 || l2 || carry) {
    int l1_node = (l1 != nullptr) ? l1->val : 0;
    int l2_node = (l2 != nullptr) ? l2->val : 0;
    int res = l1_node + l2_node + carry;
    carry = res / 10;
    res = res % 10;
    ListNode *temp = new ListNode(res);
    curr->next = temp;
    curr = curr->next;
    l1 = (l1 != nullptr) ? l1->next : nullptr;
    l2 = (l2 != nullptr) ? l2->next : nullptr;
  }
  ListNode *res = result->next;
  delete result;
  return res;
    }
};
