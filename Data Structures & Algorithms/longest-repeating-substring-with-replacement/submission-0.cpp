class Solution {
public:
    int characterReplacement(string input, int k) {
        int left = 0;
  int right = 0;
  int result = 0;
  int max_f = 0;
  unordered_map<char, int> chart_num;
  while (right < input.size()) {
    chart_num[input[right]] += 1;
    max_f = max(max_f, chart_num[input[right]]);

    while (((right - left+1) - max_f) > k) {
      chart_num[input[left]] -= 1;
      left++;
    }
    result = max(result, right - left + 1);
    right++;
  }
  return result;

    }
};
