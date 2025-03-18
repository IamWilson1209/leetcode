class Solution {
  public:
      vector<string> generateParenthesis(int n) {
          int open = n;
          int close = n;
          vector<string> ans;
          string op = "";
          solution(op, open, close, ans);
          return ans;
      }
  private: 
  /* https://leetcode.com/problems/generate-parentheses/solutions/3290261/i-bet-you-will-understand-intutive-solution-beginner-friendly-c */
      void solution(string op, int open, int close, vector<string>& ans) {
          if (open == 0 && close == 0) {
              ans.push_back(op);
              return;
          } 
          if (open == close) {
              //when count of open and close brackets are same then 
              //we have only one choice to put open bracket 
              string op1 = op;
              op1.push_back('(');
              solution(op1, open-1, close, ans);
          } else if (open == 0) {
              //only choice is to put close brackets 
              string op1 = op;
              op1.push_back(')');
              solution(op1, open, close-1, ans);
          } else {
              string op1 = op;
              string op2 = op;
              op1.push_back('(');
              op2.push_back(')');
              solution(op1, open-1, close, ans);
              solution(op2, open, close-1, ans);
          }
      }
  };