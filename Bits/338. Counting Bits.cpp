class Solution {
  public:
      vector<int> countBits(int n) {
          /*Declare vector to store ans*/
          vector<int> ans(n+1, 0);
          /*
              for loop, each loop index + 1, 
              odd: state = prev + 1;
              even: state = state/2;
          */
          if (n == 0) return ans;
          for (int i = 1; i <= n; i++) {
              if (i%2 != 0) {
                  ans[i] = ans[i-1] + 1;
              } else {
                  ans[i] = ans[i/2];
              }
          }
          return ans;
      }
  };