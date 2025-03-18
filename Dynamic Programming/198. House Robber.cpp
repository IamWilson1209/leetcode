class Solution {
  public:
      int rob(vector<int>& nums) {
          // 直接算奇數、偶數天總和不行->DP
          if (nums.size() == 1) return nums[0];
          int n = nums.size();
          vector<int> dp(n);
  
          // 前兩天，第二天要記得看max情況
          dp[0] = nums[0];
          dp[1] = max(nums[0], nums[1]);
  
          // dp[i]: 求截至目前天數為止可以偷得最多money
          for (int i = 2; i < n; i++) {
              dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
          }
          return dp[n-1];
      }
  };