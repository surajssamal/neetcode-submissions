class Solution {
public:
    int findDuplicate(vector<int>& input) {
          set<int> checking;
  for (auto l : input) {
    if (checking.find(l) != checking.end())
      return l;
    checking.insert(l);
  }
  return false;
    }
};
