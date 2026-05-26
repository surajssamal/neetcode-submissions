class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
  int l = 0, r = arr.size() - 1;
  while (l < r) {
    int resdual = arr[l] + arr[r];
    if (resdual == target) {
      return {l + 1, r + 1};
    }
    if (resdual > target) {
      r--;
    }
    if (resdual < target) {
      l++;
    }
  }
  return {};
    }
};
