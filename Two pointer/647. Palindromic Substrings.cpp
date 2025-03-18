class Solution {
  public:
      int countSubstrings(string s) {
          /* 初始狀況:s.lenght() == 1 */
          if (s.length() == 1)
              return 1;
  
          /* 全局計數: count，紀錄算了幾個 */
          /* 初始狀況->count:s.lenght() 每個單字都算一個 */
          int count = 0;
  
          /*
              重複利用原始字串->function用void
              分成奇數偶數找
          */
          for (int i = 0; i < s.length(); i++) {
              solution(s, count, i, i);
              solution(s, count, i, i + 1);
          }
  
          return count;
      }
      /*
          void(const string& s, int start, int end)
      */
      void solution (const string& s, int& count, int left, int right) {
          while (left >=0 && right < s.length() && s[left] == s[right]) {
              --left;
              ++right;
              ++count;
          }
      }
  };