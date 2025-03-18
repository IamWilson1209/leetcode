class Solution {
  public:
      uint32_t reverseBits(uint32_t n) {
          uint32_t ans = 0; /* 0000.... */
          for (int i = 0; i < 32; i++) {
              /* ans 左移一位，為下一個位元騰出空間*/
              ans <<= 1;
              /* 
                  1. (n & 1): 提取n的最低位，1 & 1 = 1; 0 & 1 = 0;
                  2.  ans |=: 把提取的位元加到ans最低位，0 | 1 = 1; 0 | 0 = 0;
              */
              ans |= (n & 1);
              /* n 右移一位 */
              n >>= 1;
          }
          return ans;
      }
  };