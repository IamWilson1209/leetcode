class Solution {
  public:
      bool backspaceCompare(string s, string t) {
          string send;
          for (char c : s) {
              if (c == '#') {
                  /*刪除最後一個*/
                  if (!send.empty()) {
                      send.pop_back();
                  }
              } else {
                  send += c;
              }
          }
          string tend;
          for (char c : t) {
              if (c == '#') {
                  /*刪除最後一個*/
                  if (!tend.empty()) {
                      tend.pop_back();
                  }
              } else {
                  tend += c;
              }
          }
          return send == tend;
      }
  };