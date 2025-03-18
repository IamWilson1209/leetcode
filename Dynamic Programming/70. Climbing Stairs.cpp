class Solution {
  public:
      int climbStairs(int n) {
          /* declare vector (0 include, so size=n+1) to store state */
          vector<int> dp(n+1);
          dp[0] = 1;
          dp[1] = 1;
          /* each state depend on former 2 states */
          for (int i = 2; i <= n; i++) {
              dp[i] = dp[i-1] + dp[i-2];
          }
          return dp[n];
      }
  };