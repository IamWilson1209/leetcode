class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        max_heap = []
        min_heap = []

        all_nums = nums1 + nums2

        for num in all_nums: 

            # 加入最大堆
            heapq.heappush(max_heap, -num) # 負數模擬最大堆

            # 將最大堆的最大值移到最小推
            max_val = -heapq.heappop(max_heap)
            heapq.heappush(min_heap, max_val)

            # 平衡兩個堆的大小
            # 如果最小堆最大堆超過一個，將最小堆的最小值移回最大堆
            if len(min_heap) > len(max_heap) + 1:
                min_val = heapq.heappop(min_heap)
                heapq.heappush(max_heap, -min_val)

        total_len = len(all_nums)
        if total_len % 2 == 0:
            return (-max_heap[0] + min_heap[0]) / 2.0
        else :
            return float(min_heap[0])