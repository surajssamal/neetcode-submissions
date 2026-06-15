class Solution {
public:

void dfs(vector<vector<char>> &grid, int i, int j, int &rows, int &max_cols) {
  if (i < 0 || j < 0 || i >= rows || j >= max_cols || grid[i][j] == '0')
    return;

  grid[i][j] = '0';
  dfs(grid, i, j + 1, rows, max_cols);
  dfs(grid, i + 1, j, rows, max_cols);
  dfs(grid, i - 1, j, rows, max_cols);
  dfs(grid, i, j - 1, rows, max_cols);
}

int numIslands(vector<vector<char>> &grid) {
  int result = 0;
  int max_cols = grid[0].size();
  int rows = grid.size();
  int islands = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < max_cols; j++) {
      if (grid[i][j] == '1') {
        dfs(grid, i, j, rows, max_cols);
        islands++;
      }
    }
  }
  return islands;
};


};
