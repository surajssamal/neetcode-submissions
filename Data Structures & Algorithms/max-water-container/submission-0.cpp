class Solution {
public:
    int maxArea(vector<int>& arr) {
        int res = 0;
        int r = arr.size() - 1;
        int l = 0;
        while (l < r) {
            if (arr[l] > arr[r]) {
            res = max(res, arr[r] * (r - l));
            r--;
            } else if (arr[l] < arr[r]) {
            res = max(arr[l] * (r - l), res);
            l++;

            } else {
            res = max(arr[l] * (r - l), res);
            l++;
            r--;
            }
        }

        return res;
    }
};
