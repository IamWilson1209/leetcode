class Solution {
  public:
      void solve(vector<vector<char>>& board) {
          if (board.empty() || board[0].empty()) return;
          
          int m = board.size();
          int n = board[0].size();
          
          // Step 1: DFS from 'O's on the borders
          // Check first and last row
          for (int j = 0; j < n; ++j) {
              if (board[0][j] == 'O') dfs(board, 0, j, m, n);
              if (board[m-1][j] == 'O') dfs(board, m-1, j, m, n);
          }
          // Check first and last column
          for (int i = 0; i < m; ++i) {
              if (board[i][0] == 'O') dfs(board, i, 0, m, n);
              if (board[i][n-1] == 'O') dfs(board, i, n-1, m, n);
          }
          
          // Step 2: Update the board
          for (int i = 0; i < m; ++i) {
              for (int j = 0; j < n; ++j) {
                  if (board[i][j] == 'O') {
                      board[i][j] = 'X'; // Unmarked 'O' becomes 'X'
                  } else if (board[i][j] == '#') {
                      board[i][j] = 'O'; // Restore marked '#' to 'O'
                  }
              }
          }
      }
      
  private:
      void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
          // Check boundaries and if the cell is 'O'
          if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
              return;
          }
          
          // Mark the current 'O' as '#' to indicate it's connected to the border
          board[i][j] = '#';
          
          // Recursively check all four directions
          dfs(board, i+1, j, m, n); // Down
          dfs(board, i-1, j, m, n); // Up
          dfs(board, i, j+1, m, n); // Right
          dfs(board, i, j-1, m, n); // Left
      }
  };