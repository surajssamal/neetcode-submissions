/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
bool check_tree(TreeNode *node, long left, long right) {
  if (!node) {
    return 1;
  }
  bool k = (left < node->val && node->val < right);
  if (!k) {
    return false;
  }
  return check_tree(node->left, left, node->val) &&
         check_tree(node->right, node->val, right);
}
public:
    bool isValidBST(TreeNode* root) {
if (!root) {
    return true;
  }
  return check_tree(root, LONG_MIN, LINE_MAX);        
    }
};
