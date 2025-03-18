class Solution {
  public:
  
      string encode(vector<string>& strs) {
          string encode;
          /*在每個str前面加上前綴#*/
          for (string str : strs) {
              encode += to_string(str.length()) + "#" + str;
          }
          return encode;
          /* encode(["Hello", "World"]) → "5#Hello6#World" */
      }
  
      vector<string> decode(string s) {
          vector<string> decode;
          int i = 0;
          while (i < s.length()) {
              /* 提取長度 */
              string len_str;
              while (i < s.length() && s[i] != '#') {
                  len_str += s[i++];
              }
              i++; // 跳過#
              int len = stoi(len_str);
              
              /* 提取子字串 */
              string str = s.substr(i, len);
              decode.push_back(str);
              i += len;
          }
          return decode;
      }
  };
  