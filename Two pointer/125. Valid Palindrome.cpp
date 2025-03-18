class Solution {
  public:
      bool isPalindrome(string s) {
          int i = 0;
          int j = s.length() - 1;
  
          while (i < j) {
              /* if j is not 字母（a-z, A-Z）或數字（0-9） */
              if (!isalnum(s[i])) {
                  i++;
                  continue;
              }
              /* if i is not char 字母（a-z, A-Z）或數字（0-9） */
              if (!isalnum(s[j])) {
                  j--;
                  continue;
              }
              /* if both are char, compare */
              if (tolower(s[j]) != tolower(s[i])) {
                  return false;
              }
              i++;
              j--;
          }
          return true;
      }
  };