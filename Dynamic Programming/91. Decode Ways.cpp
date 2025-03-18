class Solution {
  public:
      int numDecodings(string s) {
  
          if (s[0] == '0') return 0;
          
          int code_len = s.length();
          vector<int> dp(code_len+1, 0);
          // e.g. 12304
          dp[0] = 1; // 空字符串有一種解碼方式
          dp[1] = 1; // 第一個字符的解碼方式（s[0] != '0'）
          for (int i = 2; i <= code_len; i++) {
              // 檢查當前字符是否可以單獨解碼，可以則dp[i-1]解法可加入dp[i]
              // s[i-1]如果是0，不可單獨解
              if (s[i-1] != '0') {
                  dp[i] += dp[i-1];
              }
              // 檢查當前字符是否跟前一個一起解碼，可以且i-2不是0，則dp[i-2]解法可加入dp[i]
              int two_digit = (s[i-2] - '0') * 10 + (s[i-1] - '0');
              if (s[i-2] != '0' && two_digit >= 10 && two_digit <= 26) {
                  dp[i] += dp[i-2];
              }
          }
  
          return dp[code_len];
      }
  };