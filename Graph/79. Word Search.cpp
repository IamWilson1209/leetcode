class Solution {
    public:
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        bool exist(vector<vector<char>>& board, string word) {
            int rows = board.size();
            int cols = board[0].size();
    
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    if (dfs(board, word, row, col, 0)) {
                        return true;
                    }
                }
            }
            return false;
        }
    
    private:
        bool dfs(vector<vector<char>>& board, string& word, int row, int col,
                 int num_word) {
    
            // 越界檢查或字符不匹配或字符已被訪問過（標記為特殊字符）
            if (row < 0 || col < 0 || row >= board.size() ||
                col >= board[0].size() || board[row][col] != word[num_word]) {
                return false;
            }
    
            // 如果當前字符匹配，且到達單詞結尾，返回 true
            if (num_word == word.length() - 1) return true;
            
            // 暫時標記當前字符，防止重複使用
            char temp = board[row][col];
            board[row][col] = '#';
    
            // 探索四個方向
            for (const auto& dir : dirs) {
                int new_row = row + dir[0];
                int new_col = col + dir[1];
                // 若達成目標
                if (dfs(board, word, new_row, new_col, num_word + 1)) {
                    return true;
                }
            }
            // 都沒找到：回溯，恢復當前格子為未訪問
            // e.g.
            // ABC->AB，因為B方向可能還有其他C可以訪問，且未來還有機會再訪問目前的C
            board[row][col] = temp;
            return false;
        }
    };