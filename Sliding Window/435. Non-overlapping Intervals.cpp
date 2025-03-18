class Solution {
  public:
      int eraseOverlapIntervals(vector<vector<int>>& intervals) {
          // 先根據第二個元素大小進行排序
          sort(intervals.begin(), intervals.end(), compare);
  
          // vector<vector<int>> temp;
          int prev = 0;
          int count_no_overlap = 1;
          for (int i = 0; i < intervals.size(); i++) {
              // 檢查有沒有overlap
              // if (temp.empty() || temp[temp.size() - 1][1] <= interval[0]) {
              if (intervals[i][0] >= intervals[prev][1]) {
                  // temp.push_back(interval);
                  prev = i;
                  count_no_overlap++;
              }
          }
          return intervals.size() - count_no_overlap;
      }
  private:
      static bool compare (vector<int>& a, vector<int>& b) {
          return a[1] < b[1];
      }
  };