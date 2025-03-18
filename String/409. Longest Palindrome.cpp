class Solution {
  public:
      int longestPalindrome(string s) {
          vector<int> count(52, 0);
          for (char c : s) {
              if (c >= 'a' && c <= 'z') {
                  count[c - 'a']++;
              }
              if (c >= 'A' && c <= 'Z') {
                  count[c - 'A' + 26]++;
              }
          }
  
          int len = 0;
          bool hasOdd = false;
          for (int i = 0; i < count.size(); i++) {
              if (count[i]%2 == 0) {
                  len += count[i];
              } else {
                  hasOdd = true;
                  int bonus = count[i]/2;
                  len += bonus*2;
              }
          }
  
          return hasOdd ? len + 1 : len;
      }
  };