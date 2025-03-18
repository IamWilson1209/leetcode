class Solution {
  public:
      vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          vector<vector<int>> ans;
          vector<int> subset;
          sort(candidates.begin(), candidates.end());
          backtrack(candidates, target, ans, subset, 0, 0);
          return ans;        
      }
      void backtrack(vector<int> candidates, int& target, vector<vector<int>>& ans, vector<int>& subset, int idx, int sum) {
          if (sum == target) {
              ans.push_back(subset);
              return;
          }
          if (sum > target || idx >= candidates.size()) {
              return;
          }
  
          // 已經加過目前的，直接下一個
          subset.push_back(candidates[idx]); 
          backtrack(candidates, target, ans, subset, idx + 1, sum + candidates[idx]);
          subset.pop_back();
  
          while (idx + 1 < candidates.size() && candidates[idx] == candidates[idx + 1]) {
              idx++;
          }
          
          backtrack(candidates, target, ans, subset, idx + 1, sum);
      }
  };
  