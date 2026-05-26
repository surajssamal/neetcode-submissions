class Solution {
public:
    void solution(vector<int>input,vector<vector<int>>&result,vector<int>&temp,int start,int end){
        if(start>=end){
            result.push_back(temp);
            return;
        }
        temp.push_back(input[start]);
        solution(input,result,temp,start+1,end);
        temp.pop_back();
        solution(input,result,temp,start+1,end);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int>temp;
        solution(nums,result,temp,0,nums.size());
        return result;
    }
};
