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
private:
ListNode *merge_sort(ListNode *l1, ListNode *l2) {
  ListNode *dummy = new ListNode();
  ListNode *curr = dummy;
  while (l1 && l2) {
    if (l1->val < l2->val) {
      curr->next = l1;
      l1 = l1->next;
    } else {
      curr->next = l2;
      l2 = l2->next;
    }
    curr = curr->next;
  }
  if (l1) {
    curr->next = l1;
  } else {
    curr->next = l2;
  }

  return dummy->next;
};

public:
    ListNode* mergeKLists(vector<ListNode*>& inputs_ll_copy) {
          if (inputs_ll_copy.empty())
    return NULL;
  for (int i = 1; i < inputs_ll_copy.size(); i++) {
    inputs_ll_copy[i] = merge_sort(inputs_ll_copy[i - 1], inputs_ll_copy[i]);
  }
  return inputs_ll_copy.back();

    }
};
