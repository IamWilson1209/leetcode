class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        rows = len(grid)
        cols = len(grid[0])
        minutes = 0

        q = deque()
        fresh_count = 0
        for i in range (rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    q.append((i, j))
                elif grid[i][j] == 1:
                    fresh_count += 1
        
        while q:
            size = len(q)
            has_rotten = False

            for _ in range(size):
                row, col = q.popleft()

                for dx, dy in dirs:
                    new_row, new_col = row + dx, col + dy

                    if 0 <= new_row < rows and 0 <= new_col < cols and grid[new_row][new_col] == 1:
                        grid[new_row][new_col] = 2
                        q.append((new_row, new_col))
                        fresh_count -= 1
                        has_rotten = True

            if has_rotten:
                minutes += 1

        if fresh_count > 0:
            return -1
        return minutes