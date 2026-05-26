class Solution {
public:
   void solution(vector<int> &temp, set<vector<int>> &result, vector<int> &inputs,
              int i) {

  if (i >= inputs.size()) {
    result.insert(temp);
    return;
  }
  temp.push_back(inputs[i]);
  solution(temp, result, inputs, i + 1);
  temp.pop_back();
  solution(temp, result, inputs, i + 1);
}
    vector<vector<int>> subsetsWithDup(vector<int>&inputs) {
        vector<int> temp;
        sort(inputs.begin(), inputs.end());
        set<vector<int>> result;
        solution(temp, result, inputs, 0);
        return vector<vector<int>>(result.begin(), result.end());
        
    }
};
