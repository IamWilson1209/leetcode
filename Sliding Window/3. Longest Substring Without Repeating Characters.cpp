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
    
            if (s.length() == 0) return 0;
    
            int start = 0;
            int max_len = 0;
            unordered_map<char, int> record;
    
            for (int end = 0; end < s.length(); end++) {
                char cur = s[end];
    
                // 有可能重複字元在窗口外，第二個條件
                if (record.find(cur) != record.end() && record[cur] >= start) {
                    // 有找到
                    // 更新start位置
                    start = record[cur] + 1;
                }
    
                // 更新當前字元的 record
                record[cur] = end;
    
                // 更新最大長度
                max_len = max(max_len, end - start + 1);
            }
    
            return max_len;
        }
    };
    