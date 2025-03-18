class Solution {
  public:
      int trap(vector<int>& height) {
          int n = height.size();
          if (n <= 2) return 0;
  
          int total_water = 0;
          
          // 一根一根算比較好算
          for (int pos = 0; pos < n; pos++) {
              int start = pos, end = pos; // 左、右邊pointer
              int left_max = 0, right_max = 0;// 左、右邊最高
  
              while (start >= 0) {
                  // 左邊最高
                  left_max = max(left_max, height[start]);
                  start--;
              }
              while (end < n) {
                  // 右邊最高
                  right_max = max(right_max, height[end]);
                  end++;
              }
  
              int cur_water = min(left_max, right_max) - height[pos];
              if (cur_water > 0) total_water += cur_water;
          }
  
          return total_water;
      }
  };

  
  class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            if (n <= 2) return 0;
    
            int total_water = 0;
            int left = 0, right = n - 1;    // 左右指針
            int left_max = 0, right_max = 0; // 左右最大高度
            
            while (left < right) {
                // 更新左右最大高度
                left_max = max(left_max, height[left]);
                right_max = max(right_max, height[right]);
                
                // 處理較矮的一側
                if (left_max <= right_max) {
                    // 水量由左邊最大高度決定
                    total_water += left_max - height[left];
                    left++;  // 移動左指針
                } else {
                    // 水量由右邊最大高度決定
                    total_water += right_max - height[right];
                    right--; // 移動右指針
                }
            }
            
            return total_water;
        }
    };