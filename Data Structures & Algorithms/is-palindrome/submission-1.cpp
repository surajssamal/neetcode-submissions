class Solution {
public:
    bool pointer_template(char c) {
            return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9');
    };
    bool isPalindrome(string text) {
        
        int l = 0, r = text.size() - 1;
        while (l < r) {
            while (l < r && !pointer_template(text[l])) {
            l++;
            }
            while (l < r && !pointer_template(text[r])) {
            r--;
            }
            if (tolower(text[l]) != tolower(text[r])) {
            return false;
            }
            r--;
            l++;
        }
        return true;
        
    }
};
