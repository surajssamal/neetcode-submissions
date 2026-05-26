class Solution {
public:
    bool isPalindrome(string text) {
        string some="";
        for (char s : text) {
            if (isalnum(s)) {
            some += tolower(s);
            }
        }
        string reverse(some.rbegin(), some.rend());
        return reverse == some;
        
    }
};
