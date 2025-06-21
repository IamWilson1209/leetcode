class Solution {
  public:
      bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
          vector<int> ans(3, -1);
          for (auto &triplet : triplets) {
              if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                  ans[0] = max(ans[0], triplet[0]);
                  ans[1] = max(ans[1], triplet[1]);
                  ans[2] = max(ans[2], triplet[2]);
              }
          }
          return ans == target;
      }
  };