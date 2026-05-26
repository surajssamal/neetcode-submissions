class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int time) {
  int left = 1;
  int right = *max_element(piles.begin(), piles.end());
  int res = right;
  while (left <= right) {
    int mid = (left + right) / 2;
    int total_va = 0;
    for (auto pile : piles) {
      total_va += (pile + mid - 1) / mid;
    }
    if (total_va <= time) {
      res = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return res;
    }
};
