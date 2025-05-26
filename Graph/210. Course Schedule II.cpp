class Solution {
  public:
      vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          unordered_map<int, vector<int>> preMap;
  
          /* 先用map儲存<course, pre(陣列)> */
          for (vector<int> prerequisite : prerequisites) {
              preMap[prerequisite[0]].push_back(prerequisite[1]);
          }
  
          /* 確保每個課程都在 preMap 中，即使某些課程沒有後續課程（入度0） */
          for (int i = 0; i < numCourses; i++) {
              preMap[i];
          }
  
          vector<int> indeg(numCourses, 0); /* 記錄每個課程需要先修的課程數量 */
          vector<bool> vis(numCourses,
                           false); /* 記錄課程是否已被加入結果，初始為 false */
  
          /* 遍歷 preMap，對於每個課程的後續課程的入度加 1：indeg[v]++ */
          for (auto& iter : preMap) {
              for (int i = 0; i < iter.second.size(); i++) {
                  indeg[iter.second[i]]++;
              }
          }
  
          /* 將所有入度為 0 的課程（無需先修的課程）加入隊列
           * q，因為這些課程可以直接修讀 */
          queue<int> q;
          for (int i = 0; i < indeg.size(); i++) {
              if (indeg[i] == 0) {
                  q.push(i);
              }
          }
  
          /*
              BFS 過程：
              BFS 從入度為 0 的課程開始（代表沒有任何後續課程）
          */
          vector<int> ans;
          while (!q.empty()) {
              vis[q.front()] = true; /* 每次從隊列取出一個課程（q.front()），標記為已訪問（vis[course]
                                        = true）。 */
              vector<int> courses = preMap[q.front()]; /* 獲取該課程的後續課程列表
                                                          k = mp[q.front()] */
  
              for (int i = 0; i < courses.size(); i++) {
                  /* 將此課程的入度減 1（因為當前課程已完成） */
                  if (indeg[courses[i]] > 0) {
                      indeg[courses[i]]--;
                  }
                  /* 如果課程的入度變為 0 且尚未訪問，將 course[i] 加入隊列 */
                  if (!vis[courses[i]] && indeg[courses[i]] == 0) {
                      q.push(courses[i]);
                  }
              }
              ans.push_back(q.front());
              q.pop();
          }
  
          for (int i = 0; i < ans.size(); i++) {
              cout << ans[i] << ' ';
          }
  
          reverse(ans.begin(), ans.end());
          if (ans.size() != numCourses)
              return {};
  
          return ans;
      }
  };