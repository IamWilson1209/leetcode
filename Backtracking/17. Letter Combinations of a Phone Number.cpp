class Solution {
  public:
      vector<string> letterCombinations(string digits) {
          vector<string> ans;
          if (digits.empty()) return ans;
          unordered_map<int, vector<char>> phoneMap;
          string comb = "";
          phoneMap[2] = {'a', 'b', 'c'};
          phoneMap[3] = {'d', 'e', 'f'};
          phoneMap[4] = {'g', 'h', 'i'};
          phoneMap[5] = {'j', 'k', 'l'};
          phoneMap[6] = {'m', 'n', 'o'};
          phoneMap[7] = {'p', 'q', 'r', 's'};
          phoneMap[8] = {'t', 'u', 'v'};
          phoneMap[9] = {'w', 'x', 'y', 'z'};
          backtrack(digits, ans, phoneMap, comb, 0);
          return ans;
      };
      void backtrack(string& digits, vector<string>& ans, unordered_map<int, vector<char>>& phoneMap, string& comb, int start) {
          if (start == digits.length()) {
              ans.push_back(comb);
          }
          int digit = digits[start] - '0';
          auto chars = phoneMap[digit];
  
          for (char c : chars) {
              comb.push_back(c); // 添加當前字母
              backtrack(digits, ans, phoneMap, comb, start + 1); // 遞迴下一個數字
              comb.pop_back(); // 回溯，移除當前字母
          }
      }
  }
  ;