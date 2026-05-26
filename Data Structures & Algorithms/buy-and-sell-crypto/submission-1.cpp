class Solution {
public:
    int maxProfit(vector<int>& stocks_price) {
  int left = 0;
  int right = left + 1;
  int result = 0;
  while (right < stocks_price.size()) {
    if (stocks_price[left] < stocks_price[right]) {
      result = max(stocks_price[right] - stocks_price[left], result);
    } else {
      left = right;
    }
    right++;
  }
  return result;
    }
};
