class Solution {
  public:
      string countAndSay(int n) {
          return solution(n, "1");
      }
  
  private:
      string solution(int n, string rle) {
          if (n == 1) return rle; /* 終止條件：n=1 時返回當前字串 */
          
          string ans;
          int count = 1;
          char cur = rle[0]; /* 當前計數的字符 */
          
          for (int i = 1; i < rle.size(); i++) {
              if (rle[i] == cur) {
                  count++;
              } else {
                  ans += to_string(count) + cur;
                  cur = rle[i];
                  count = 1;
              }
          }
          /* 數到最後還沒結束，處理最後一組字符 */
          ans += to_string(count) + cur;
          
          return solution(n - 1, ans);
      }
  };