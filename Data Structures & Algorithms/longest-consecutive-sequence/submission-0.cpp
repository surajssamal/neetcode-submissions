class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> set_arr(arr.begin(), arr.end());
        int res = 0;
        for (auto s : set_arr) {
            int streak = 0, current = s;
            while (set_arr.find(current) != set_arr.end()) {
            current += 1;
            streak += 1;
            }
            res = max(streak, res);
        }
        return res;
    }
};
