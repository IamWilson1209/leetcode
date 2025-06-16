class Solution {
  public:
      int minCostConnectPoints(vector<vector<int>>& points) {
          /*
              Prim 演算法：
              從一個起點開始，逐步將頂點加入生成樹
              每次選擇當前生成樹到所有未訪問頂點的最小成本邊，將對應的頂點加入生成樹
              更新生成樹後，重新計算到所有未訪問頂點的距離，並選擇下一個最小成本邊
  
              這個演算法：
              從一個起點開始，每次選擇當前生成樹到未訪問頂點的最小成本邊，將新頂點加入生成樹，並更新到其他未訪問頂點的距離
              頂點數為 n，邊數為 O(n²)（完全圖）
              優先佇列操作（插入和刪除）為 O(log n)
              總時間複雜度為 O(n² log n)，因為對於每個頂點，需遍歷所有其他頂點並進行優先佇列操作
          */
          int numPoints = points.size();
          int minCost = 0;
          vector<bool> visited(numPoints, false);
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; /* 頂點pair：<最小成本邊, 頂點> */
          unordered_map<int, int> minDistMap;  /* 紀錄各個頂點的最短曼哈頓距離，<頂點, 曼哈頓距離> */
          pq.push({0, 0}); /* 從0開始，成本為0 */
  
          while (!pq.empty()) {
              /* 取出最小成本邊 */
              auto edge = pq.top();
              pq.pop();
              int cost = edge.first;
              int point = edge.second;
  
              /* 檢查最小成本邊對應的頂點有沒有找過最小成本 */
              if (visited[point]) {
                  continue;
              }
  
              visited[point] = true;
              minCost += cost;
  
              /* 遍歷每個頂點，計算這些頂點與目前取出頂點的曼哈頓距離 */
              for (int p = 0; p < numPoints; p++) {
                  if (!visited[p]) {
                      int dist = abs(points[point][0] - points[p][0]) +
                                 abs(points[point][1] - points[p][1]);
                      if (minDistMap.find(p) == minDistMap.end() ||
                          dist < minDistMap[p]) {
                          minDistMap[p] =
                              dist; /* <頂點, 最小曼哈頓距離>
                                       暫時加入目前最短曼哈頓距離，用於比較用 */
                          pq.push({dist, p});
                      }
                  }
              }
          } // 將 return 移到這裡
          return minCost;
      }
  };