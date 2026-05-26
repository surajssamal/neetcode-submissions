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
int layers(TreeNode *node) {
  if (!node) {
    return 0;
  }
  return 1 + max(layers(node->left), layers(node->right));
}
void travesal(TreeNode *node, int i, vector<vector<int>> &res) {
  if (!node) {
    return;
  }
  travesal(node->left, i + 1, res);
  travesal(node->right, i + 1, res);
  res[i].push_back(node->val);
}
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
     int n = layers(root);
  vector<vector<int>> result(n);
  travesal(root, 0, result);
  return result; 
    }
};
