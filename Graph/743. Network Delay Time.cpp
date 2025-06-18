class Solution {
  public:
      int networkDelayTime(vector<vector<int>>& times, int n, int k) {
          vector<vector<pair<int, int>>> adjList(n+1); /* adjList[u] 儲存 {v, w} 的配對，表示從節點 u 到節點 v 的邊，權重為 w。 */
          for (int i = 0; i < times.size(); i++) {
              adjList[times[i][0]].push_back({times[i][1], times[i][2]});
          }
  
          /* 最小堆：儲存 {distance, node}，按 distance 升序排序，每次取出到起點k最小距離的節點 */
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
          pq.push({k, 0}); // 起點k，距離0
  
          /* 記錄從起點 k 到每個節點的最短距離 */
          vector<int> minDist(n+1, INT_MAX);
          minDist[k] = 0;
  
          /* 
              Dijkstra 演算法：
              從起點開始，逐步探索距離最小的節點
              通過當前節點更新到其他節點的距離
              重複直到所有節點處理完畢
          */
          while (!pq.empty()) {
              /* 每次取出距離起點 k 最近距離的點 */
              auto it = pq.top();
              int node = it.first;
              int weight = it.second; // 起點 k 到 node 的當前距離
              pq.pop();
  
              /* 遍歷 node 的所有鄰邊 */
              for (auto neighbor: adjList[node]) {
                  int neighborNum = neighbor.first;
                  int neighborWeight = neighbor.second;
                  
                  /* 從起點 k 經過 node 到 neighborNum 的總距離（wt + neighborWt）小於當前neighbor到k的最短時間 */
                  if (weight + neighborWeight < minDist[neighborNum]) {
                      minDist[neighborNum] = weight + neighborWeight; // 更新鄰居到起點k的最近距離
                      pq.push({neighborNum, minDist[neighborNum]}); // push鄰居，下次Dijkstra從距離k最近的點開始
                  }
              }
          }
  
          /* 計算結果：找出到所有節點的最短距離中的最大值 */
          int ans = -1;
          for (int i = 1; i <= n; i++) {
              if (minDist[i] == INT_MAX) return -1; // 如果有節點無法到達，返回 -1
              if (ans < minDist[i]) ans = minDist[i]; // 更新
          }
          return ans;
      }
  };