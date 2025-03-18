class Solution {
  public:
      vector<int> productExceptSelf(vector<int>& nums) {
          int n = nums.size();
          vector<int> ans(n);
          /* 先算 nums i 以左所有數字的乘積 */
          ans[0] = 1;
          for (int i = 1; i < n; i++) {
              ans[i] = ans[i-1] * nums[i-1];
          }
          /* 再算 nums i 以右所有數字的乘積 */
          int right_product = 1;
          for (int i = n - 1; i >= 0; i--) {
              ans[i] *= right_product;
              right_product *= nums[i];
          }
          /* 相乘即為結果 */
          return ans;
      }
  };
  