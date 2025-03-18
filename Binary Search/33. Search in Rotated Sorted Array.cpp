class Solution {
  public:
      int search(vector<int>& nums, int target) {
          int left = 0;
          int right = nums.size() - 1;
          
          while (left <= right) {
              int mid = left + (right - left) / 2;
              if (nums[mid] == target) return mid;

              // 左有序
              if (nums[mid] >= nums[left]) {
                  // 鎖定在左邊
                  if (nums[left] <= target && nums[mid] > target) {
                      right = mid - 1;
                  } else {
                      left = mid + 1;
                  }
              } else { // 右有序
                  // 鎖定在右邊
                  if (nums[right] >= target && nums[mid] < target) {
                      left = mid + 1;
                  } else {
                      right = mid - 1;
                  }
  
              }
          }
          return -1;
      }
  };