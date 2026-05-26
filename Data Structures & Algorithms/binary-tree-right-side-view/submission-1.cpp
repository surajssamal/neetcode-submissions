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
void solution(TreeNode *root, vector<int> &res,int depth) {
  if (!root) {
    return;
  }
  if(res.size()==depth){
  res.push_back(root->val);
  }
  solution(root->right, res,depth+1);
  solution(root->left,res,depth+1);
}
public:
    vector<int> rightSideView(TreeNode* root) {
     vector<int> result;
     solution(root, result,0);
     return result;
    }
};
