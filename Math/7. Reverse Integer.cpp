class Solution {
  public:
      int reverse(int x) {
          int ans = 0;
          while (x != 0) {
              int digit = x % 10;
  
              /* 
                  如果反轉後的整數超出 32 位元有符號整數範圍 -2^31 ~ 2^31, [-2147483648, 2147483647] ，則返回 0
                  反轉後等等還會 * 10，提前檢查
              */
              if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                  return 0;
              }
  
              ans = ans * 10 + digit;
              x = x / 10;
          }
  
          return ans;
      }
  };