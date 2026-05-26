class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> res;

        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
            };
            int l = i + 1, r = arr.size() - 1;
            while (l < r) {
            int result = arr[i] + arr[r] + arr[l];

            if (result > 0) {
                r--;
            } else if (result < 0) {
                l++;
            } else {
                res.push_back({arr[i], arr[r], arr[l]});
                l++;
                r--;
                while (arr[l] == arr[l - 1] && l < r) {
                l++; // Skip all duplicates for left pointer
                }
            }
            }
        }
        return res;
    }
};
