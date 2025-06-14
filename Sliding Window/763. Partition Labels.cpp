class Solution {
  public:
      /*
      走到某個位置，發現後面不會有目前需要的單字了，就把小組定下來，記錄長度，然後開始新小組
      */
      vector<int> partitionLabels(string s) {
          unordered_map<char, int> lastOccur;
          for (int i = 0; i < s.size(); i++) {
              lastOccur[s[i]] = i;
          }
  
          vector<int> ans;
          int start = 0, end = 0;
  
          for (int i = 0; i < s.size(); i++) {
              end = max(end, lastOccur[s[i]]);
              if (i == end) {
                  ans.push_back(end - start + 1);
                  start = i + 1;
              }
          }
          return ans;
      }
  };