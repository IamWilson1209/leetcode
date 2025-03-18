class Solution {
  public:
      vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          int rows = image.size();
          int cols = image[0].size();
          vector<vector<int>> ans = image;
          int initValue = image[sr][sc];
          ans[sr][sc] = color;
          dfs(image, sr, sc, color, ans, initValue);
          return ans;
      }
      void dfs(vector<vector<int>>& image, int row, int col, int color,
               vector<vector<int>>& ans, int& initValue) {
          
          // ans[row][col] = color; 也可以
  
          for (vector<int> dir : dirs) {
              int newRow = row + dir[0];
              int newCol = col + dir[1];
              if (newRow >= 0 && newRow < image.size() &&
                  newCol >= 0 && newCol < image[0].size() &&
                  ans[newRow][newCol] != color && // 未被填充過
                  image[newRow][newCol] == initValue) { // 顏色匹配
                  ans[newRow][newCol] = color;
                  dfs(image, newRow, newCol, color, ans, initValue);
              }
          }
      }
  };