class Solution {
  public:
      int longestConsecutive(vector<int>& nums) {
          unordered_set<int> numSet(nums.begin(), nums.end());
  
          int maxLength = 0;
          for (int num : nums) {
              if (numSet.find(num - 1) == numSet.end()) {
                  int curLength = 1;
                  while (numSet.find(num + curLength) != numSet.end()) {
                      curLength++;
                  }
                  maxLength = max(curLength, maxLength);
              }
          }
  
          return maxLength;
      }
  };
  
  

  class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            /* 可能會有的情境 */
            if (nums.empty()) return 0;
    
            /* 宣告最小堆積 */
            priority_queue<int, vector<int>, greater<>> pq;
    
            /* 推入最小堆積 */
            for (int num : nums) {
                pq.push(num);
            }
    
            int max_len = 1;
            int cur_len = 1;
            int prev = pq.top();
            pq.pop();
    
            /* 依序遍歷 */
            while (!pq.empty()) {
                int cur = pq.top();
                pq.pop();
                if (cur == prev + 1) {
                    cur_len++;
                    max_len = max(max_len, cur_len);
                } else if (cur == prev) {
                    continue;
                } else {
                    cur_len = 1;
                }
                prev = cur;
            }
            return max_len;
        }
    };
    
    