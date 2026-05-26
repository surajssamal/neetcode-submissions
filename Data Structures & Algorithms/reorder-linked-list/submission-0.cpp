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
    void reorderList(ListNode* head) {
  vector<ListNode *> values;
  ListNode *curr = head;
  while (curr) {
    values.push_back(curr);
    curr = curr->next;
  }
  int left = 0, right = values.size() - 1;
  while (left < right) {
    values[left]->next = values[right];
    left += 1;
    if (left >= right) {
      break;
    }
    values[right]->next = values[left];
    right -= 1;
  }
  values[left]->next = nullptr;
    }
};
