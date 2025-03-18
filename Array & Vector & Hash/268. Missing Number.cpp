class Solution {
  public:
      int missingNumber(vector<int>& nums) {
          /* 1. Declare total number of ((1+n)*n)/2 */
          int range = nums.size();
          int total = ((1+range)*range)/2;
          
          /* 2. for loop 0 ~ range; minus curr num */
          for (int i = 0; i < range; i++) {
              total = total - nums[i];
          }
  
          /* return ans */
          return total;
      }
  };