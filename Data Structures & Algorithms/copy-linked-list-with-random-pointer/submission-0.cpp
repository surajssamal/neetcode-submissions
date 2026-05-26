/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map<Node *, Node *> record;  
  Node *curr = head;                     
  while (curr) {                         
    Node *temp = new Node(curr->val);    
    record[curr] = temp;                 
    curr = curr->next;                   
  }                                      
  curr = head;                           
  while (curr) {                         
    Node *copy = record[curr];           
    copy->next = record[curr->next];     
    copy->random = record[curr->random]; 
    curr = curr->next;                   
  }                                      
  return record[head];                   
   
    }
};
