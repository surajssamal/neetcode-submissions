class Solution {
public:
    double findMedianSortedArrays(vector<int>& input_1, vector<int>& input_2) {
       set<int> input_num(input_1.begin(), input_1.end());
  input_num.insert(input_2.begin(), input_2.end());
  int left = 0;
  int right = input_num.size() - 1;
  int mid = (left + right) / 2;
  if ((right + 1) % 2 != 0) {
    auto it = input_num.begin();
    advance(it, mid);
    return *it;
  }

  auto it1 = input_num.begin();
  auto it2 = input_num.begin();
  advance(it1, mid);
  advance(it2, mid + 1);
  double res = (*it1 + *it2) / 2.0;
  return res;   
    }
};
