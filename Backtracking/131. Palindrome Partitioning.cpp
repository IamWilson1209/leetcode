class Solution {

  /*
  
  以 s = "aab" 為例，模擬回溯過程，展示如何生成結果：
  
      初始：s = "aab", v = [], ans = []
      solve("aab", [], ans)：
          i=0：截取 "a"，是回文：
          v = ["a"], t = "ab", 調用 solve("ab", ["a"], ans)
  
          solve("ab", ["a"], ans)：
          i=0：截取 "a"，是回文：
              v = ["a", "a"], t = "b", 調用 solve("b", ["a", "a"], ans)
              solve("b", ["a", "a"], ans)：
                  i=0：截取 "b"，是回文：
                  v = ["a", "a", "b"], t = "", 調用 solve("", ["a", "a", "b"], ans)
                  solve("", ["a", "a", "b"], ans)：
                      s 為空，將 v = ["a", "a", "b"] 加入 ans
                      ans = [["a", "a", "b"]]
                      回溯：v.pop_back() → v = ["a", "a"]
  
          i=1：截取 "ab"，不是回文，跳過。
          回溯：v.pop_back() → v = ["a"]
              i=1：截取 "aa"，是回文：
              v = ["aa"], t = "b", 調用 solve("b", ["aa"], ans)
              solve("b", ["aa"], ans)：
                  i=0：截取 "b"，是回文：
                  v = ["aa", "b"], t = "", 調用 solve("", ["aa", "b"], ans)
                  solve("", ["aa", "b"], ans)：
                      s 為空，將 v = ["aa", "b"] 加入 ans
                      ans = [["a", "a", "b"], ["aa", "b"]]
                      回溯：v.pop_back() → v = ["aa"]
  
          i=2：截取 "aab"，不是回文，跳過。
          返回：ans = [["a", "a", "b"], ["aa", "b"]]
  
  */
  public:
      vector<vector<string>> partition(string s) {
          vector<string> v; /* 當前分割的子字串集合（一個可能的分割結果） */
          vector<vector<string>> ans;
          solve(s, v, ans);
          return ans;
      }
  
      bool isp(string s) {
          int end = s.length() - 1;
          int start = 0;
          while (start <= end) {
              if (s[start] != s[end]) return false;
              end--;
              start++;
          }
          return true;
      }
  
      void solve(string &s, vector<string> &v, vector<vector<string>> &ans) {
          if (s == "") {
              ans.push_back(v);
          }
          for (int i = 0; i < s.length(); i++) {
              if (isp(s.substr(0, i+1))) {
                  v.push_back(s.substr(0, i+1)); /* 先推入當前子字串 */
                  string t = s.substr(i+1); /* i+1 後的子字串 */
                  solve(t, v, ans); /* 遞迴檢查 i+1 後的子字串 */
                  v.pop_back();
              }
          }
      }
  };