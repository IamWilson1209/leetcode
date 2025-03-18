class Solution {
  public:
      int characterReplacement(string s, int k) {
          unordered_map<char, int> windowCharCount; // 紀錄目前窗口的所有單字出現數量
          int windowCharMaxCount = 0; // 用來儲存當前窗口內頻率最高的字符數量
          int ans = 0;
          int left = 0, right = 0;
  
          while (right < s.length()) {
              // 每次右移都要先記錄
              windowCharCount[s[right]]++;
              windowCharMaxCount = max(windowCharMaxCount,  windowCharCount[s[right]]);
              
              // 如果已經沒得換了
              if ((right - left + 1) - k > windowCharMaxCount) {
                  // window右移
                  windowCharCount[s[left]]--;
                  left++;
              }
              
              // 更新答案
              ans = max(right - left + 1, ans);
              right++;
          }
          return ans;
      }
  };