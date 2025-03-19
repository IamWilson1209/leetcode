class Solution {
  public:
      string minWindow(string s, string t) {
          vector<int> base(52, 0);
          // 初始化
          for (char c : t) {
              if (c >= 'a' && c <= 'z') base[c - 'a']++;
              if (c >= 'A' && c <= 'Z') base[c - 'A' + 26]++;  
          }
  
          // 滑動窗口
          vector<int> count(52, 0);
          int totalMatchCount = t.length();
          int windowMatchCount = 0;
          int start = 0, minStart = 0, minLen = INT_MAX;
          for (int end = 0; end < s.length(); end++) {
              // 將當前字符加入window
              char c = s[end];
              int idx = (c >= 'a' && c <= 'z') ? (c - 'a') : (c - 'A' + 26);
              count[idx]++;
              
              // 如果當前字符在 t 中，且次數未超標，增加 windowMatchCount
              if (base[idx] > 0 && count[idx] <= base[idx]) {
                  windowMatchCount++;
              }
  
              // 當窗口包含 t 的所有字符時，縮減窗口，用while可能前面會有無關的字，可以loop掉
              while (windowMatchCount == totalMatchCount && start <= end) {
                  // 更新最新答案的長度
                  if (end - start + 1 < minLen) {
                      minLen = end - start + 1;
                      minStart = start;
                  }
  
                  // 縮減窗口，移除左邊字符
                  char leftChar = s[start];
                  int leftIdx = (leftChar >= 'a' && leftChar <= 'z') ? (leftChar - 'a') : (leftChar - 'A' + 26);
                  count[leftIdx]--;
  
                  // 如果移除的字符影響了匹配條件，減少 windowMatchCount
                  if (base[leftIdx] > 0 && count[leftIdx] < base[leftIdx]) {
                      windowMatchCount--;
                  }
                  start++;
              }
  
          }
          return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
      }
  };