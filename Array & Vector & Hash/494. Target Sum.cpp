class Solution {
  public:
      int findTargetSumWays(vector<int>& nums, int target) {
          return solve(nums, target, 0, 0);
      }
  
      int solve(vector<int>& nums, int target, int idx, int curSum) {
          if (idx == nums.size()) {
              return curSum == target ? 1 : 0;
          }
  
          int plus = solve(nums, target, idx + 1, curSum + nums[idx]);
          int minus = solve(nums, target, idx + 1, curSum - nums[idx]);
  
          return plus + minus; // 類似左子樹+右子樹
      }
  };