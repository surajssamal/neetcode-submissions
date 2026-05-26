class Solution {
public:
    int maxProfit(vector<int>& stocks_price) {
  int minum = stocks_price[0];
  int result = 0;
  for (auto s : stocks_price) {
    result = max(result, s - minum);
    minum = min(minum, s);
  }
  return result;

    }
};
