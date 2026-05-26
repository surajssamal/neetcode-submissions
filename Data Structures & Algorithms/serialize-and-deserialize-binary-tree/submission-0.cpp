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

class Codec {

private:
  // turing treenode to string;
  vector<string> string_val;
  void string_vec(TreeNode *root) {
    if (!root) {
      string_val.push_back("null");
      return;
    }
    string_val.push_back(to_string(root->val));
    string_vec(root->left);
    string_vec(root->right);
  }
  string string_conversion(int n) {
    string string_res = string_val[0];

    for (int i = 1; i < n; i++) {
      if (string_val[i] == "null") {
        string_res += ",null";
      } else {
        string_res += "," + string_val[i];
      }
    }
    return string_res;
  }
  // turing string to treenode;

  vector<string> turing_back_vector(string &string_res) {
    vector<string> result;
    size_t i = 0;
    string delimiter = ",";
    while ((i = string_res.find(delimiter)) != string::npos) {
      result.push_back(string_res.substr(0, i));
      string_res.erase(0, i + delimiter.size());
    }
    result.push_back(string_res);
    return result;
  }
  //
  TreeNode *turing_node(vector<string> inputs, int &i) {
    if (inputs[i] == "null") {
      i++;
      return nullptr;
    }
    TreeNode *node = new TreeNode(stoi(inputs[i]));
    i++;
    node->left = turing_node(inputs, i);
    node->right = turing_node(inputs, i);
    return node;
  }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string_vec(root);
    string string_res = string_conversion(string_val.size());
    return string_res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string string_inp) {
        vector<string> vec_turn = turing_back_vector(string_inp);
    int i = 0;
    TreeNode *root = turing_node(vec_turn, i);
    return root;
    }
};
