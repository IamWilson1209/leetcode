class Solution {
  public:
      vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      int numIslands(vector<vector<char>>& grid) {
          
          int rows = grid.size();
          int cols = grid[0].size();
          vector<vector<bool>> visited(rows, vector<bool>(cols, false));
          int island_count = 0;
  
          for (int row = 0; row < rows; row++) {
              for (int col = 0; col < cols; col++) {
                  if (grid[row][col] == '1' && !visited[row][col]) {
                      island_count++;
                      dfs(grid, visited, row, col);
                  }
              }
          }
          return island_count;
      }
      void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
          int rows = grid.size();
          int cols = grid[0].size();
  
          if (row < 0 || row >= rows || col < 0 || col >= cols || // 邊界檢查
              visited[row][col] || grid[row][col] == '0') {       // 已訪問或是水
              return;
          }
  
          visited[row][col] = true; // 標記當前格子
  
          for (auto dir : dirs) { // 檢查四個方向
              int newRow = row + dir[0];
              int newCol = col + dir[1];
              dfs(grid, visited, newRow, newCol); // 遞迴標記連通陸地
          }
      }
  };