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
    bool hasCycle(ListNode* head) {
        ListNode *current = head;
        unordered_set<ListNode*> checking;
        while (current) {
            if (checking.find(current->next)!=checking.end()) {
                return true;
            }
        checking.insert(current);
        current =current->next;
        }
        return false;
    }

};
