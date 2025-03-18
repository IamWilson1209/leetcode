class Solution {
  public:
      int myAtoi(string s) {
          int i = 0;
          int sign = 1; // 正負號，1 表示正，-1 表示負
          long result = 0; // 使用 long 處理溢出
  
          // 跳過前面空格
          while (i < s.length() && s[i] == ' ') {
              i++;
          }
  
          // 如果已經到達字串末尾，返回 0
          if (i >= s.length()) return 0;
  
          // 檢查正負號
          if (s[i] == '-' || s[i] == '+') {
              sign = (s[i] == '-') ? -1 : 1;
              i++;
          }
  
          // 處理數字
          while (i < s.length() && isdigit(s[i])) {
              result = result * 10 + (s[i] - '0');
  
              // 檢查溢出 條件4
              if (result > INT_MAX) {
                  return (sign == 1) ? INT_MAX : INT_MIN;
              }
              i++;
          }
  
          // 應用正負號並返回
          return sign * result;
      }
  };