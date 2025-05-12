class Solution {
  public:
      vector<int> dailyTemperatures(vector<int>& temperatures) {
          int n = temperatures.size();
          vector<int> ans(n, 0); // 紀錄在i之後多少天會有更高的溫度
  
          for (int i = n-2; i >= 0; i--) {
              int next_day = i+1;
              while (next_day < n && temperatures[next_day] <= temperatures[i]) {
                  if (ans[next_day] == 0) {
                      // 不會有更高的了
                      // next_day設到底
                      next_day = n;
                      break;
                  }
                  // 還有更高的，繼續找，把天數加進去
                  next_day += ans[next_day];
              }
              if (next_day < n) ans[i] = next_day - i;
          }
          return ans;
      }
  };
  