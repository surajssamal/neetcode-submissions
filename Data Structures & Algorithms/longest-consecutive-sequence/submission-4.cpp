class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int res = 0;
        unordered_set<int> arr_set(arr.begin(), arr.end());
        for (auto n : arr_set) {
            if (arr_set.find(n - 1) == arr_set.end()) {
            int length = 0;
            while (arr_set.find(n + length) != arr_set.end()) {
                length += 1;
            }
            res = max(res, length);
            }
        }
        return res;
    }
};
