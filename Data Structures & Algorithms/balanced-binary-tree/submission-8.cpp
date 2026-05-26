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
    vector<int> solution(TreeNode *node){
        if(!node){
            return {1,0};
        }
        vector<int>left =solution(node->left);
        vector<int>right =solution(node->right);
        bool check =(left[0]==1&&right[0]==1)&&(abs(left[1]-right[1])<=1);
        int height = 1+max(solution(node->left)[1],solution(node->right)[1]);
        return {check?1:0,height};
    }
public:
    bool isBalanced(TreeNode* root) {
        return solution(root)[0];
    }
};
