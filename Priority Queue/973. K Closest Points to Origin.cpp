class Solution {
  public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          // 使用最小堆，存儲 {距離平方, 索引}
          priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> minHeap;
          
          // 將所有點的距離和索引加入堆
          for (int i = 0; i < points.size(); i++) {
              int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];  // 距離平方
              minHeap.push({dist, i});
              if (minHeap.size() > k) minHeap.pop();  // 保持堆大小為 k
          }
          
          // 從堆中提取 k 個點的坐標
          vector<vector<int>> result;
          while (!minHeap.empty()) {
              int idx = minHeap.top().second;
              result.push_back(points[idx]);
              minHeap.pop();
          }
          
          return result;
      }
  };