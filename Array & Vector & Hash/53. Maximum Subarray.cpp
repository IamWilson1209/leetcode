class Solution {
  public:
      int maxSubArray(vector<int>& nums) {
          int cur_sum = 0;
          int max_sum = INT_MIN;
  
          for (int num : nums) {
              cur_sum = max(num, num + cur_sum);
              max_sum = max(cur_sum, max_sum);
          }
  
          return max_sum;
      }
  };