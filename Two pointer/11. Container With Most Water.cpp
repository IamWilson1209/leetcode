class Solution {
  public:
      int maxArea(vector<int>& height) {
          int left = 0;
          int right = height.size() - 1;
          int ans = INT_MIN;
          while (left < right) {
              int cur = 0;
              if (height[left] < height[right]) {
                  cur = height[left] * (right - left);
                  left++;
              } else {
                  cur = height[right] * (right - left);
                  right--;
              }
              if (cur > ans) {
                  ans = cur;
              }
          }
          return ans;
      }
  };


  class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
            int max_volumn = 0;
            while (left < right) {
                int cur_volumn = (right - left) * min(height[left], height[right]);
                height[left] < height[right] ? left++ : right--;
                max_volumn = max(cur_volumn, max_volumn);
            }
            return max_volumn;
        }
    };