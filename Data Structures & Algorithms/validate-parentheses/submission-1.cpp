class Solution {
public:
    bool isValid(string input_param) {
        stack<char> stackinput;
        map<char, char> last_symbols{{'}', '{'}, {')', '('}, {']', '['}};
        for (char s : input_param) {
            if (last_symbols.count(s)) {
            if (!stackinput.empty() && last_symbols[s] == stackinput.top()) {
                stackinput.pop();
            } else {
                return false;
            }

            } else {
            stackinput.push(s);
            }
        }
        return stackinput.empty();
   
    }
};
