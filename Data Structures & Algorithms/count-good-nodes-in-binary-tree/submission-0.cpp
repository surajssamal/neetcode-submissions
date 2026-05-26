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
int dfs(TreeNode *node, int max_num) {
  if (!node) {
    return 0;
  }
  int res = (node->val >= max_num) ? 1 : 0;
  max_num = max(node->val, max_num);
  res += dfs(node->left, max_num);
  res += dfs(node->right, max_num);
  return res;
}
public:
    int goodNodes(TreeNode* root) {
 int result = dfs(root, root->val);
  return result;       
    }
};
