class Solution {
  public:
      void nextPermutation(vector<int>& nums) {
          /* 找到第一個：前一個元素小於當前元素，並設為 i */
          int i = nums.size() - 1;
          while (i > 0 && nums[i-1] >= nums[i]) {
              i--;
          }
  
          /* 如果跑到底都沒找到，代表完全是降序，reverse */
          if (i == 0) {
              reverse(nums.begin(), nums.end());
              return;
          }
          
          /* 在 nums[i] 到末尾的 "降序子陣列中"，找到最小的、比 nums[i-1] 大的元素 */
          int j = nums.size() - 1;
          while (j >= i && nums[j] <= nums[i-1]) {
              j--;
          }
  
          /* swap(最小、i之前出現過的最小) */
          swap(nums[i-1], nums[j]);
  
          /* reverse i 之前的 vector */
          reverse(nums.begin() + i, nums.end());
      }
  };