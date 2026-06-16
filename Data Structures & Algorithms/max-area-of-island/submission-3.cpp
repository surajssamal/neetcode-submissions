class Solution {
public:
  int max_val = 0;
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dfs(vector<vector<int>> &grid, int r, int c) {
  if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||
      grid[r][c] == 0) {
    return 0;
  }

  grid[r][c] = 0;
  int res = 1;
  for (int i = 0; i < 4; i++) {
    res += dfs(grid, r + directions[i][0], c + directions[i][1]);
  }
  return res;
}

int maxAreaOfIsland(vector<vector<int>> &grid) {
  int max_cols = grid[0].size();
  int rows = grid.size();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < max_cols; j++) {
      if (grid[i][j] == 1) {
        max_val = max(dfs(grid, i, j), max_val);
      }
    }
  }
  return max_val;
}
 
        
    
};
