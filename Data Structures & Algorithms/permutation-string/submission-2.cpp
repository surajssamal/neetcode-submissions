class Solution {
public:
    bool checkInclusion(string s1, string s2) {
          vector<int> s1_map(26, 0);
  vector<int> s2_map(26, 0);
  for (int i = 0; i < s1.size(); i++) {
    s1_map[s1[i] - 'a'] += 1;
    s2_map[s2[i] - 'a'] += 1;
  }
  int matches = 0;
  for (int i = 0; i < 26; i++) {
    if (s1_map[i] == s2_map[i]) {
      matches += 1;
    }
  }
  int left = 0;
 
  for(int right=s1.size();right<s2.size();right++) {
    if (matches == 26) {
      return true;
    }
    int index = s2[right] - 'a';
    s2_map[index] += 1;
    if (s1_map[index] == s2_map[index]) {
      matches += 1;
    } else if (s1_map[index] + 1 == s2_map[index]) {
      matches -= 1;
    }

    index = s2[left] - 'a';
    s2_map[index] -= 1;
    if (s1_map[index] == s2_map[index]) {
      matches += 1;
    } else if (s1_map[index] - 1 == s2_map[index]) {
      matches -= 1;
    }

    left++;
  }
  return matches == 26;
    }
};
