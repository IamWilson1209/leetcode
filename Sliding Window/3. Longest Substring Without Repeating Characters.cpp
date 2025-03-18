class Solution {
  public:
      int (string s) {
          if (s.length() == 0) return 0;  
          if (s.length() == 1) return 1;  
          
          /* start end pointer*/
          int start = 0;  
          int end = 0;    
          int max_len = 0; 
          map<char, int> record; // <字符, 位置索引>
          
          /* while loop: end < s.length */
          while (end < s.length()) {
              /* 當前字符 */
              char c = s[end];
  
              /* 如果字符已存在，更新子字串起點 */
              if (record.find(c) != record.end()) {  
                  start = max(start, record[c] + 1);
              }
  
              /* 
                  不管新字符有沒有存在於sub_str，都要: 
                  1. 更新當前字符最新位置 
                  2. 更新最大長度
                  3. 移動終點
              */
              record[c] = end;  
              max_len = max(max_len, end - start + 1); 
              end++;         }
  
          return max_len;
      }
  };

  class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // <char, index>
            unordered_map<char, int> visited; 
            int start = 0;
            int gmax = 0;
    
            for (int i = 0; i < s.length(); i++) {
                if (visited.find(s[i]) != visited.end() && visited[s[i]] >= start) {
                    start = visited[s[i]] + 1;
                }
                visited[s[i]] = i;
                gmax = max(gmax, i - start + 1);
            }
    
            return gmax;
        }
    };
    