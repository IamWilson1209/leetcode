class Solution(object):
    def longestIncreasingPath(self, matrix):
        if not matrix or not matrix[0]:
            return 0
        
        # 初始化矩陣尺寸
        rows, cols = len(matrix), len(matrix[0])
        indegree = [[0] * cols for _ in range(rows)]  # 入度陣列
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # 四個方向：上、下、左、右
        
        # 計算入度
        for i in range(rows):
            for j in range(cols):
                for di, dj in directions:
                    ni, nj = i + di, j + dj
                    if 0 <= ni < rows and 0 <= nj < cols and matrix[ni][nj] > matrix[i][j]:
                        indegree[ni][nj] += 1
        
        # 初始化佇列和 DP 陣列
        q = deque()
        dp = [[1] * cols for _ in range(rows)]  # 每個單元格初始路徑長度為 1
        for i in range(rows):
            for j in range(cols):
                if indegree[i][j] == 0:
                    q.append((i, j))
        
        # 拓撲排序
        max_path = 1
        while q:
            i, j = q.popleft()
            for di, dj in directions:
                ni, nj = i + di, j + dj
                if 0 <= ni < rows and 0 <= nj < cols and matrix[ni][nj] > matrix[i][j]:
                    dp[ni][nj] = max(dp[ni][nj], dp[i][j] + 1)
                    max_path = max(max_path, dp[ni][nj])
                    indegree[ni][nj] -= 1
                    if indegree[ni][nj] == 0:
                        q.append((ni, nj))
        
        return max_path