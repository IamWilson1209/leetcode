class Solution {
  public:
      vector<vector<int>> ans;
      vector<vector<int>> permute(vector<int>& nums) {
          permutation(nums, 0);
          return ans;
      }
      void permutation(vector<int>& nums, int start) {
          if (nums.size() == start) {
              ans.push_back(nums);
          }
          for (int i = start; i < nums.size(); i++) {
              swap(nums[i], nums[start]);
              permutation(nums, start+1);
              swap(nums[i], nums[start]);
          }
      }
  };