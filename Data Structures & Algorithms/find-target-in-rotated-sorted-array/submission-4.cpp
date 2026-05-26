class Solution {
public:
    int search(vector<int>& inputs, int target) {
     int left = 0;
  int right = inputs.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (inputs[mid] == target) {
      return mid;
    }
    if (inputs[left] <= inputs[mid]) {
      if (target > inputs[mid] || target < inputs[left]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    } else {
      if (target < inputs[mid] || target > inputs[right]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }
  return -1;
    }
};
