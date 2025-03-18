class Solution {
  public:
      vector<vector<int>> ans;
      vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          // 目前嘗試的組合
          vector<int> comb;
          // function()
          combination(candidates, target, 0, comb, 0);
          return ans;
  
      }
      void combination(vector<int>& candidates, int target, int start, vector<int>& comb, int sum) {
          if (target == sum) {
              ans.push_back(comb);
              return;
          }
          if (sum > target || start >= candidates.size()) {
              return;
          }
          // 假設 candidates = [2, 3]
          // 把當前數字（candidates[start]）push進comb，比如 start = 0 時塞入 2
          comb.push_back(candidates[start]);
          // 繼續嘗試目前start位置的組合
          // comb = [2]; start = 0; sum + candidates[start] = 2
          combination(candidates, target, start, comb, sum + candidates[start]);
          // pop掉2
          comb.pop_back();
          // 嘗試下一個start位置的組合，comb = []; start = 1(元素3); sum = 0
          combination(candidates, target, start + 1, comb, sum);
  
      }
  };