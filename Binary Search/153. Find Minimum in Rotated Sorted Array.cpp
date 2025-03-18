class Solution {
  public:
      int findMin(vector<int>& nums) {
          // binary search
          int ans = INT_MAX;
          int left = 0;
          int right = nums.size() - 1;
          // 防止[1]這種狀況出現，所以要用<=
          while (left <= right) {
              int mid = left + (right - left) / 2;
              
              if (nums[mid] >= nums[left]) {
                  // 左邊按照排序
                  // left 最小
                  // 更新
                  ans = min(nums[left], ans);
                  left = mid + 1;
              } else {
                  // 右邊按照順序
                  ans = min(nums[mid], ans);
                  right = mid - 1;
              }
          }
          return ans;
      }
  };