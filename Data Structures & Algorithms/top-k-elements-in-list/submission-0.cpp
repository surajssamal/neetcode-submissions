class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> unir_arr;
        for (auto num : nums) {
            unir_arr[num]++;
        }
        vector<pair<int, int>> pair_arr;
        for (auto r : unir_arr) {
            pair_arr.push_back({r.second, r.first});
        }
        sort(pair_arr.rbegin(), pair_arr.rend());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pair_arr[i].second);
        }
        return result;
    }
};
