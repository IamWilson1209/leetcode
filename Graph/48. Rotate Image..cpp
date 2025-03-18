class Solution {
  public:
      void rotate(vector<vector<int>>& matrix) {
          int rows = matrix.size();
          int cols = matrix[0].size();
  
          // 轉置
          for (int row = 0; row < rows; row++) {
              for (int col = 0; col < row; col++) {
                  swap(matrix[row][col], matrix[col][row]);
              }
          }
  
          // 反轉
          for (int row = 0; row < rows; row++) {
              reverse(matrix[row].begin(), matrix[row].end());
          }
      }
  };