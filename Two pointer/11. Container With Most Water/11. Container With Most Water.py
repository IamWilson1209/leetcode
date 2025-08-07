class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        start = 0 
        end = len(height) - 1
        max_volume = 0

        while start < end:
            cur_volume = min(height[start], height[end]) * (end - start)
            max_volume = max(max_volume, cur_volume)
            if height[start] < height[end]:
                start += 1
            else: 
                end -= 1

        return max_volume