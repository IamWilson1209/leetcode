class Solution {
private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // dfs不適合，嘗試bfs
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q; // 儲存腐爛橘子的座標
        int freshCount = 0;      // 統計新鮮橘子數量
        int minute = 0;          // 記錄時間

        // 找到所有腐爛橘子並統計新鮮橘子
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // 如果沒有新鮮橘子，直接返回 0
        if (freshCount == 0) return 0;

        while (!q.empty()) {
            int size = q.size(); // 當前範圍的腐爛橘子數量
            bool hasRotten = false; // 是否有新橘子腐爛

            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (auto dir : dirs) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if (newRow >= 0 && newRow < rows &&
                        newCol >= 0 && newCol < cols &&
                        grid[newRow][newCol] == 1) {
                            grid[newRow][newCol] = 2; // 標記為腐爛
                            q.push({newRow, newCol}); // 加入下一層
                            freshCount--;
                            hasRotten = true;
                        }
                }
            }
            // 如果這一輪有橘子腐爛，時間增加
            if (hasRotten) minute++;
        }

        return freshCount == 0 ? minute : -1;
    }
};