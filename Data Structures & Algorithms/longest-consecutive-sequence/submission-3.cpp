class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()==0){return 0;};
        int res = 0;
        int streak = 0, current = arr[0], i = 0;
        sort(arr.begin(), arr.end());
        while (i < arr.size()) {
            if (arr[i] != current) {
            current = arr[i];
            streak = 0;
            }
            while (arr[i] == current) {
            i++;
            }
            current += 1;
            streak += 1;
            res = max(res, streak);
        }
        return res;
    }
};
