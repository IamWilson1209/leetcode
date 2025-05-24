class Solution {
  public:
      vector<int> sortedSquares(vector<int>& nums) {
          int n = nums.size();
          vector<int> ans(n);
          int left = 0, right = n - 1, pos = n - 1;
  
          while (left <= right) {
              int leftSquare = nums[left] * nums[left];
              int rightSquare = nums[right] * nums[right];
              if (rightSquare < leftSquare) {
                  ans[pos] = leftSquare;
                  left++;
              } else {
                  ans[pos] = rightSquare;
                  right--;
              }
              pos--;
          }
  
          return ans;
      }
  };