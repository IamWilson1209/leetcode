class Solution {
  public:
      bool checkValidString(string s) {
          int n = s.size();
          /* 「未配對的左括號數量」的最小可能值 */
          int leftMin = 0;
          /* 「未配對的左括號數量」的最大可能值 */
          int leftMax = 0;
          for (int i = 0; i < n; i++) {
              if (s[i] == '(') {
                  leftMin++; // 最小數量加 1，因為多了一個左括號
                  leftMax++; // 最大數量也加 1，因為沒有其他選擇
              }
              else if (s[i] == ')') {
                  leftMin--;
                  leftMax--;
              }
              else {
                  leftMin--; // 如果把 '*' 當作 ')'，會配對掉一個左括號，所以最小數量減 1
                  leftMax++; // 如果把 '*' 當作 '('，會增加一個左括號，所以最大數量加 1
              }
              /*
              leftMax 是把 '*' 都當作 '(' 的最大左括號數
              如果這都變成負數，說明右括號太多，怎麼選 '*' 都配對不了
              */
              if (leftMax < 0) return false;
              /*
              leftMin 負數表示把 '*' 當 ')' 時右括號太多
              但 '*' 還可以是空或 '('，所以設回 0 表示「最少 0 個左括號」
              */
              if (leftMin < 0) leftMin = 0;
          }    
          return leftMin == 0;
      }
  };