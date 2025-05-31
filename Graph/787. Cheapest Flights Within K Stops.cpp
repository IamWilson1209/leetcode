class Solution {
  private:
      int ans = 0;
  public:
      int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
          /* pair<destination, cost> */
          vector<vector<pair<int, int>>> adj(n); 
          
          /* adj[i]: node i 的鄰居節點以及 cost */
          for (auto flight : flights) {
              adj[flight[0]].push_back({flight[1], flight[2]});
          }
  
          /* node, cost */
          queue<pair<int, int>> q;
          q.push({src, 0});
  
          vector<int> minCost(n, INT_MAX); /* minCost to each node */
          int stops = 0; /* 紀錄 steps */
          
          /* 當 q 不為空 && stops 未超過指定 k */
          while (!q.empty() && stops <= k) { 
              /* 當本層還有 node */
              int size = q.size();
              while (size--) { 
                  auto [currNode, cost] = q.front();
                  q.pop();
                  /* 對於這層的所有 node，loop 所有鄰居節點 */
                  for (auto& [neighbour, price] : adj[currNode]) {
                      /* 如果更新後的 price + cost < 此鄰居節點目前的最低 cost，更新最低 cost */
                      if (price + cost < minCost[neighbour]) {
                          minCost[neighbour] = price + cost;
                          q.push({neighbour, minCost[neighbour]}); /* 鄰居節點 push 到 neighbor */
                      }
                  }
              }
              stops++;    
          }
          /* 沒有reach dst */
          if (minCost[dst] == INT_MAX) return -1;
          return minCost[dst]; 
      }
  };