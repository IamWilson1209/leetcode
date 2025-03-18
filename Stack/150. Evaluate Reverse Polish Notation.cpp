class Solution {
  public:
      int applyOperation(int a, int b, string op) {
          if (op == "+") {
              return a + b;
          } else if (op == "-") {
              return a - b;
          } else if (op == "*") {
              return a * b;
          } else if (op == "/") {
              return a / b;
          } else {
              throw invalid_argument("Invalid operator");
          }
      }
  
      int evalRPN(vector<string>& tokens) {
          stack<int> st;
          for (int i = 0; i < tokens.size(); i++) {
              if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                  tokens[i] == "/") {
                  int num1 = st.top();
                  st.pop();
                  int num2 = st.top();
                  st.pop();
                  int current = applyOperation(num2, num1, tokens[i]); 
                  st.push(current);  
              } else {
                  st.push(stoi(tokens[i]));
              }
          }
          return st.top();
      }
  };