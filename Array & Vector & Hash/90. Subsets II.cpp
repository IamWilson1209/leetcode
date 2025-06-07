class Solution {
  public:
      vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          sort(nums.begin(), nums.end());
          vector<vector<int>> res = {{}};
  
          /*
          
          處理 nums[0] = 1：
          n = 1，遍歷 res（只有 []）：
          基於 [] 生成 [1]，std::find 未找到，加入 res。
          res = [[], [1]]
          處理 nums[1] = 2：
          n = 2，遍歷 res（[], [1]）：
          基於 [] 生成 [2]，std::find 未找到，加入 res。
          基於 [1] 生成 [1,2]，std::find 未找到，加入 res。
          res = [[], [1], [2], [1,2]]
          
          */
  
          for (int num : nums) {
              int n = res.size(); 
              /* 記錄當前 res 的大小（即現有子集的數量），遍歷現有子集 */
              for (int i = 0; i < n; i++) {
                  vector<int> subset = res[i];
                  subset.push_back(num);
                  /* 檢查重複子，檢查新生成的 subset 是否已經存在於 res 中 */
                  if (find(res.begin(), res.end(), subset) == res.end()) {
                      res.push_back(subset); /* 如果 find 返回 res.end()（表示沒找到），則將 subset 加入 res */
                  }
              }
          }
  
          return res;
      }
  };