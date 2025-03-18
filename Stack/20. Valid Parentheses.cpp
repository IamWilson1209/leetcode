class Solution {
  public:
      bool isValid(string s) {
          /* 1. stack */
          stack<char> stack_VP;
          /*  
              2. for loop for all char
              if (、{、[ then push into stack; else )、}、]
              take stack.top() from stack
          */
          for (char c : s) {
              if (c == '(' || c == '{' || c == '[') {
                  stack_VP.push(c);
              } else {
                  /* if not pair return false */
                  if (stack_VP.empty() ||
                  (c == ')' && stack_VP.top() != '(') || 
                  (c == '}' && stack_VP.top() != '{') ||
                  (c == ']' && stack_VP.top() != '[')) {
                      return false;
                  } else {
                      /* else return true */
                      stack_VP.pop();
                  }
              }
          }
          /* 
              There may be some condition "["
              checkout whether stack is empty()
          */
          return stack_VP.empty();
      }
  };