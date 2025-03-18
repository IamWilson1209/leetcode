class Solution {
  public:
      bool wordBreak(string s, vector<string>& wordDict) {
          /*
              需要考慮前一個state，不能用雙指標
          */
          /* unordered_set<string>: 裝字典，vector<bool> dp table */
          unordered_set<string> dict(wordDict.begin(), wordDict.end()); // dp[i] 表示 s[0:i] 可拆分
          vector<bool> dp(s.length() + 1, false);
          dp[0] = true;
          /* 
              要loop看字是否存在於字典中，
              且每個組合都要檢查到
          */
          for (int end = 1; end <= s.length(); end++) {
              for (int start = 0; start < end; start++) {
                  /*
                      若前start個字可拆分(所以可以排除start前不在wordDict的情況)
                      而且start開始的end-start個字可以找到，紀錄dp[end]可拆分*/
                  if (dp[start] && dict.count(s.substr(start, end - start))) {
                      dp[end] = true;
                      break;
                  }
              }
          }
          return dp[s.length()];
      }
  };
  