class Solution {
public:

void dfs(vector<int> inputs, vector<vector<int>> &result, vector<int> &temp,
         vector<bool> &tick) {
  if (temp.size() == inputs.size()) {
    result.push_back(temp);
    return;
  }

  for (int i = 0; i < inputs.size(); i++) {
    if (!tick[i]) {
      temp.push_back(inputs[i]);
      tick[i] = true;
      dfs(inputs, result, temp, tick);
      temp.pop_back();
      tick[i] = false;
    }
  }
}
    vector<vector<int>> permute(vector<int>&inputs) {
vector<vector<int>> result;
  vector<int> temp;
  vector<bool> tick(inputs.size(), false);
  dfs(inputs, result, temp, tick);
  return result;        
    }
};
