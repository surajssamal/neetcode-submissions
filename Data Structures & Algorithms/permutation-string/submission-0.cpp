class Solution {
public:
    bool checkInclusion(string s_1, string s_2) {
     sort(s_1.begin(), s_1.end());
  for (int i = 0; i < s_2.size(); i++) {
    for (int j = i; j < s_2.size(); j++) {
      string substr = s_2.substr(i, j - i + 1);
      sort(substr.begin(), substr.end());
      if (substr == s_1) {
        return true;
      }
    }
  }
  return false;

    }
};
