class Solution {
  private:
      int ans = 0;
      vector<vector<int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
      
      int dfs(int row, int col, vector<vector<int>>& grid) {
          // 檢查邊界和是否為有效格子
          if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1) {
              return 0;
          }
          
          // 標記為已訪問
          grid[row][col] = '#';
          
          // 當前格子計入面積
          int area = 1;
          
          // 探索四個方向
          for (const auto& dir : dirs) {
              int newRow = row + dir[0];
              int newCol = col + dir[1];
              area += dfs(newRow, newCol, grid);
          }
          
          return area;
      }
      
  public:
      int maxAreaOfIsland(vector<vector<int>>& grid) {
          if (grid.empty() || grid[0].empty()) return 0;
          
          int rows = grid.size();
          int cols = grid[0].size();
          
          // 遍歷網格，只對 '1' 啟動 DFS
          for (int row = 0; row < rows; ++row) {
              for (int col = 0; col < cols; ++col) {
                  if (grid[row][col] == 1) {
                      int area = dfs(row, col, grid);
                      ans = max(ans, area);
                  }
              }
          }
          
          return ans;
      }
  };