class Solution {
  public:
      bool checkInclusion(string s1, string s2) {
          if (s1.length() > s2.length()) return false;
  
          // s1_count：記錄 s1 中各字符的出現次數
          // window：記錄當前滑動窗口中各字符的出現次數
          // len: 窗口大小，固定為 s1 長度
          vector<int> s1_count(26, 0), window(26, 0);
          int len = s1.length(); 
  
          // 統計 s1 的字符頻率
          for (char c : s1) {
              s1_count[c - 'a']++;
          }
  
          // 初始化第一個窗口
          for (int i = 0; i < len; i++) {
              window[s2[i] - 'a']++;
          }
  
          // 檢查第一個窗口   
          if (s1_count == window) return true;
          
          // 滑動窗口
          for (int i = len; i < s2.length(); i++) {
              window[s2[i] - 'a']++;           // 添加新字符
              window[s2[i - len] - 'a']--;     // 移除舊字符
              if (s1_count == window) return true;
          }
          
          return false;        
      }
  };
  