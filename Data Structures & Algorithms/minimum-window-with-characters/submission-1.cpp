class Solution {
public:
    string minWindow(string s, string t) {
         if (t.empty()|| t.size()>s.size()) {
    return "";
  }
  unordered_map<char, int> s_map;
  unordered_map<char, int> t_map;
  for (auto c : t) {
    t_map[c] += 1;
  }
  int need = t_map.size(), have = 0;
  pair<int, int> result = {-1, -1};
  int min_lenth = INT_MAX;
  int left = 0;
  for (int right = 0; right < s.size(); right++) {
    char index = s[right];
    s_map[index] += 1;
    if (t_map.count(index) && s_map[index] == t_map[index]) {
      have += 1;
    }
    while (have == need) {
      if ((right - left + 1) < min_lenth) {
        result = {left, right};
        min_lenth = right - left + 1;
      }
      index = s[left];
      s_map[index] -= 1;
      if (t_map.count(index) && s_map[index] < t_map[index]) {
        have -= 1;
      }
      left += 1;
    }
  }
  int l = result.first, r = result.second + 1;
  string res = "";
  for (int i = l; i < r; i++) {
    res += s[i];
  }
  return min_lenth==INT_MAX?"":res;

    }
};
