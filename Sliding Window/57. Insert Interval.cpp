class Solution {
  public:
      vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
          vector<vector<int>> ans;
          int index = 0;
          // 無關的
          while (index < intervals.size() && intervals[index][1] < newInterval[0]) {
              ans.push_back(intervals[index]);
              index++;
          }
          // 處裡重疊的
          while (index < intervals.size() && intervals[index][0] <= newInterval[1]) {
              newInterval[0] = min(newInterval[0], intervals[index][0]);
              newInterval[1] = max(newInterval[1], intervals[index][1]);
              index++;
          }
          // 加進合併後的新區間
          ans.push_back(newInterval);
          // 剩下的
          while (index < intervals.size()) {
              ans.push_back(intervals[index]);
              index++;
          }
  
          return ans;
      }
  };