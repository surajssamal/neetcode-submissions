


class Solution {
public:
    ListNode* reverseList(ListNode* input) {
        ListNode *prev = nullptr;
        ListNode *current = input;
        while (current) {
          ListNode *temp = current->next;
          current->next = prev;
          prev = current;
          current = temp;
        }
    return prev;
    }
};
