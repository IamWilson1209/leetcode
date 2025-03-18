class Solution {
  public:
      void setZeroes(vector<vector<int>>& matrix) {
          int rows = matrix.size();
          int cols = matrix[0].size();
          vector<bool> rows_zero(rows, false);
          vector<bool> cols_zero(cols, false);
  
          for (int row = 0; row < rows; row++) {
              for (int col = 0; col < cols; col++) {
                  if (matrix[row][col] == 0) {
                      if (!rows_zero[row]) rows_zero[row] = true;
                      if (!cols_zero[col]) cols_zero[col] = true;
                  }
              }
          }
  
          for (int row = 0; row < rows; row++) {
              if (rows_zero[row]) {
                  for (int col = 0; col < cols; col++) {
                      matrix[row][col] = 0;
                  }
              }
          }
  
          for (int col = 0; col < cols; col++) {
              if (cols_zero[col]) {
                  for (int row = 0; row < rows; row++) {
                      matrix[row][col] = 0;
                  }
              }
          }
  
      }
  };