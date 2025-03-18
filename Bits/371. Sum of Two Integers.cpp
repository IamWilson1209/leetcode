class Solution {
  public:
      int getSum(int a, int b) {
          /*
              a：初始時是第一個加數，迴圈中儲存當前的「不含進位的和」。
              b：初始時是第二個加數，迴圈中儲存當前的「進位」。
              buff：臨時變數，用來儲存每次計算的進位。
          */
          unsigned int buff;
          do {
              buff = a & b; // & 運算只有在對應位都是 1 時結果為 1，表示該位需要進位
              a ^= b; // XOR 計算不含進位的和
              b = buff << 1; // 將進位左移一位，準備加到下一輪的結果中
          } while (buff); // 如果還有進位
          return a;
      }
  };