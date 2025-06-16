class Solution {
  private:
      vector<int> parent; /* 每個幫派的代表頂點，初始時每個頂點是自己的父節點 */
      vector<int> rank;   /* 記錄每個幫派的規模，用於優化合併操作，減少樹的高度 */
  
      /* Find：如果不是自己當老大，找更高層的老大，並直接連到它，下次查詢更快 */
      int detectCycle(int point) {
          if (parent[point] != point) {
              parent[point] = detectCycle(parent[point]);
          }
          return parent[point];
      }
  
      /* Union：將頂點 u 和 v 幫派合併 */
      void joinSet(int u, int v) {
          int rootU = detectCycle(u),
              rootV = detectCycle(v); // 找到 u 和 v 的老大
          if (rootU != rootV) {       // 如果不在同一個幫派
              if (rank[rootU] > rank[rootV])
                  parent[rootV] = rootU; // 小的幫派併入大的
              else if (rank[rootU] < rank[rootV])
                  parent[rootU] = rootV;
              else { // 幫派規模相同，隨意選一個當大老大
                  parent[rootV] = rootU;
                  rank[rootU]++; // 大老大的規模加 1
              }
          }
      }
  
  public:
      vector<int> findRedundantConnection(vector<vector<int>>& edges) {
          int n = edges.size();
          parent.resize(n + 1, 1);
          rank.resize(n + 1, 0);
  
          /* 初始化所有頂點，自己是自己的parent */
          for (int i = 1; i <= n; i++)
              parent[i] = i;
  
          /* 處理每條邊 */
          for (auto& edge : edges) {
              int u = edge[0], v = edge[1];
              /* 如果 u 和 v 已連通，這條邊形成環 */
              if (detectCycle(u) == detectCycle(v))
                  return edge;
              /* 沒有的話join set */
              joinSet(u, v);
          }
  
          return {}; /* 理論上不會到這（題目保證有環）*/
      }
  };
  
  /*
      1. Think of building a tree by adding edges one by one.
      2. If a new edge connects two nodes that are already connected, it creates a
     cycle.
      3. To track connections efficiently, we use DSU (Disjoint Set Union).
      4. DSU groups nodes into sets, where each set represents a connected
     component.
      5. When adding an edge, if the nodes are in the same set, the edge is
     redundant—it forms a cycle.
      6. The last such edge in the input is the answer.
  
      Case 1: No Cycle (Normal Tree Growth)
      Edges: A-B, B-C, C-D
      Add A-B: A and B are now connected.
      Add B-C: B (connected to A) and C merge.
      Add C-D: C (connected to A-B) and D merge.
      Result: All nodes form a single chain. No cycles.
      Case 2: Cycle Detected (Redundant Edge)
  
      Edges: A-B, B-C, C-A
      Add A-B: Connected.
      Add B-C: Connected (A-B-C).
      Add C-A: A and C are already connected! This edge creates a cycle.
      Result: C-A is redundant. Return it.
      Case 3: Multiple Components Merged
  
      Edges: X-Y, Y-Z, W-V, V-W (typo: should be V-U?), Y-W
      Add X-Y: Connected.
      Add Y-Z: Connected (X-Y-Z).
      Add W-V: New component (W-V).
      Add V-W: Already connected. Redundant!
      Result: Return V-W (last redundant edge).
  */