class Solution {
  public:
      // nums = [1, 2]
      vector<vector<int>> subsets(vector<int>& nums) {
          vector<vector<int>> ans;
          vector<int> subset;
          backtracking(nums, 0, subset, ans);
          return ans;
      }
      // 當前考慮的元素index，當前正在構建的子集
      void backtracking(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& ans) {
          if (i >= nums.size()) {
              ans.push_back(subset);
              return;
          }
          // i = 1（考慮 nums[1] = 2）
          subset.push_back(nums[i]); // subset = [1, 2]
          backtracking(nums, i+1, subset, ans); // 選擇加入 2
          subset.pop_back(); // 回復subset = [1]
          backtracking(nums, i+1, subset, ans); // 選擇不加入 2
      }
  };
  
  /*
      class Solution {
      public:
          vector<vector<int>> subsets(vector<int>& nums) {
              vector<vector<int>> ans;
              ans.push_back({}); // 加入空子集作為起點
  
              for (int num : nums) {
                  int size = ans.size();
                  for (int i = 0; i < size; i++) {
                      vector<int> subset = ans[i]; // 複製現有子集
                      subset.push_back(num);       // 加入當前元素
                      ans.push_back(subset);       // 將新子集加入 ans
                  }
              }
  
              return ans;
          }
      };
  
      初始狀態
      ans = [ [] ]（包含空子集）
      步驟 1: 處理 num = 1
      num = 1
      size = ans.size() = 1
      內層迴圈 i = 0:
      subset = ans[0] = []
      subset.push_back(1) -> subset = [1]
      ans.push_back([1])
      更新後: ans = [ [], [1] ]
      步驟 2: 處理 num = 2
      num = 2
      size = ans.size() = 2
      內層迴圈 i = 0:
      subset = ans[0] = []
      subset.push_back(2) -> subset = [2]
      ans.push_back([2])
      內層迴圈 i = 1:
      subset = ans[1] = [1]
      subset.push_back(2) -> subset = [1, 2]
      ans.push_back([1, 2])
      更新後: ans = [ [], [1], [2], [1, 2] ]
  */