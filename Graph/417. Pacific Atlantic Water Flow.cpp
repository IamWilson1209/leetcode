class Solution {
  public:
      const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
          int rows = heights.size();
          int cols = heights[0].size();
          vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
          vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
          vector<vector<int>> ans;
  
          for (int row = 0; row < rows; row++) {
              dfs(row, 0, pacific, heights); // 左邊 
              dfs(row, cols - 1, atlantic, heights); // 右邊
          }
          for (int col = 0; col < cols; col++) {
              dfs(0, col, pacific, heights); // 上邊
              dfs(rows - 1, col, atlantic, heights); // 下邊
          }
          for (int i = 0; i < rows; i++) {
              for (int j = 0; j < cols; j++) {
                  // 兩個都可以走到
                  if (pacific[i][j] && atlantic[i][j]) {
                      ans.push_back({i, j});
                  }
              }
          }
  
          return ans;
      }
      // 用來dfs從邊邊開始可以走到的{row, col}
      void dfs(int row, int col, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
          // 邊邊一定可以到
          ocean[row][col] = true;
          // 遍歷四個方向
          for (int i = 0; i < dirs.size(); i++) {
              int nextRow = row + dirs[i][0];
              int nextCol = col + dirs[i][1];
              if (nextRow >= 0 && nextCol >= 0 && nextRow < ocean.size() &&
                  nextCol < ocean[0].size() &&
                  // 還沒走過
                  !ocean[nextRow][nextCol] &&
                  // 下一個位置更大
                  heights[nextRow][nextCol] >= heights[row][col]) {
                  dfs(nextRow, nextCol, ocean, heights);
              }
          }
      }
  };