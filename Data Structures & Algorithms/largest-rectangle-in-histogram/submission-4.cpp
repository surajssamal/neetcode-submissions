class Solution {
public:
    int largestRectangleArea(vector<int>& something) {
          int i = 0, j = 1;
  int max_value = 0;
  int n = something.size();

  while (i < n) {
    while (something[i] <= something[j] && j < n) {
      j++;
    }

    int k = i;
    int back_res = 0;
    while (something[k - 1] > something[i] && k >= 1) {
      back_res += 1;
      k--;
    }
    max_value = max(max_value, something[i] * (j - (i - back_res)));
    i++;
    j = i + 1;
  }
  return max_value;

    }
};
