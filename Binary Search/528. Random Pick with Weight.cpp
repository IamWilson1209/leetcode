class Solution {
  private:
      vector<int> weights; /* 儲存前綴和 */
      int totalSum = 0;
  public:
      /* w = [1,3] → weights = [1,4]，表示區間 (0,1] 和 (1,4] */
      Solution(vector<int>& w) {
          int curSum = 0;
          for (int weight : w) {
              curSum += weight;
              weights.push_back(curSum);
          }
          totalSum = curSum;
      }
      
      int pickIndex() {
          int target = rand() % totalSum + 1; /* 隨機生成 [1, totalSum] */
          int left = 0, right = weights.size();
  
          while (left < right) {
              int mid = left + (right - left) / 2;
              if (target > weights[mid]) {
                  left = mid + 1;
              } else {
                  right = mid;
              }
          }
  
          return left;
      }
  };
  
  /**
   * Your Solution object will be instantiated and called as such:
   * Solution* obj = new Solution(w);
   * int param_1 = obj->pickIndex();
   */