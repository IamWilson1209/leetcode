class Solution {
  public:
      int coinChange(vector<int>& coins, int amount) {
          vector<int> dp(amount+1, INT_MAX);
          dp[0] = 0;
          
          for (int amt = 1; amt <= amount; amt++) {
              // for迴圈: 檢查有沒有超過當前coin
              for (int coin : coins) {
                  if (amt - coin >= 0 && dp[amt - coin] != INT_MAX) {
                      // 超過此coin值
                      // dp[amt]: 因為有可能會算到其他coin相減的結果，要比較
                      dp[amt] = min(dp[amt - coin] + 1, dp[amt]);
                  }
              }
          }
          return dp[amount] == INT_MAX ? -1 : dp[amount];
      }
  };