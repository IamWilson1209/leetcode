class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        ans = []

        for cur in range(len(nums)):
            
            if cur > 0 and nums[cur] == nums[cur - 1]:
                continue

            start = cur + 1
            end = len(nums) - 1

            while start < end:
                total = nums[cur] + nums[start] + nums[end]

                if total > 0: 
                    end -= 1
                elif total < 0:
                    start += 1
                else:
                    ans.append([nums[cur], nums[start], nums[end]])
                    start += 1

                    # -1, -1, 0, 1, 2
                    while start < end and nums[start] == nums[start - 1]:
                        start += 1

        return ans 