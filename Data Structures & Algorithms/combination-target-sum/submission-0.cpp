class Solution {
public:
   void solution(vector<vector<int>>&result,int index, vector<int> input, int target, vector<int> &temp) {
  if (target == 0) {
    result.push_back(temp);
    return;
  } else if (target < 0|| index >=input.size()) {
    return;
  }
  temp.push_back(input[index]);
  solution(result,index, input, target - input[index], temp);
  temp.pop_back();
  solution(result,index + 1, input, target, temp);
} 
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        solution(result,0,nums,target,temp);
        return result;
    };
};
