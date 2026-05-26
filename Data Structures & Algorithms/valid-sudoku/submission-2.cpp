class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& inp) {
        map<int, set<char>> rows;
        map<int, set<char>> cols;
        map<pair<int, int>, set<int>> squares;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
            if (inp[i][j] == '.') {
                continue;
            };
            pair<int, int> squarKey = {i / 3, j / 3};
            if (rows[i].count(inp[i][j]) || cols[j].count(inp[i][j]) ||
                squares[squarKey].count(inp[i][j])) {
                return false;
            };
            rows[i].insert(inp[i][j]);
            cols[j].insert(inp[i][j]);
            squares[squarKey].insert(inp[i][j]);
            }
        }
        return true;
       
    }
};
