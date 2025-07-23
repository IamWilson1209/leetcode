class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        search_map = {}
        ans = []

        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in search_map:
                ans.append(search_map[complement])
                ans.append(i)
                return ans
            else:
                search_map[nums[i]] = i

        return ans