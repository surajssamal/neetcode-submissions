class Solution {

private:
vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
public:
    void solution(string digits,int i,string temp,vector<string>&result){
        if(temp.size()==digits.size()){
            result.push_back(temp);
            return;
        }
        string chars = digitToChar[digits[i]-'0'];
        for(char &c:chars){
            solution(digits,i+1,temp+c,result);
        } 
    }

    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if(digits.empty())
            return result;
        solution(digits,0,"",result);
        return result;
    }
};
