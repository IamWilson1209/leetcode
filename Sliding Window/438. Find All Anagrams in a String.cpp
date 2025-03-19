class Solution {
  public:
      vector<int> findAnagrams(string s, string p) {
          vector<int> ans;
          if (p.length() > s.length()) return ans;
          
          // 建立 p 的字元頻率
          vector<int> pCount(26, 0);
          vector<int> window(26, 0);
          
          // 統計 p 的字元頻率
          for (char c : p) {
              pCount[c - 'a']++;
          }
          
          // 初始化第一個window
          for (int i = 0; i < p.length(); i++) {
              window[s[i] - 'a']++;
          }
          if (window == pCount) ans.push_back(0);
          
          // 滑動窗口
          for (int i = p.length(); i < s.length(); i++) {
              window[s[i] - 'a']++;              // 添加新字元
              window[s[i - p.length()] - 'a']--; // 移除舊字元
              if (window == pCount) ans.push_back(i - p.length() + 1);
          }
          
          return ans;
      }
  };