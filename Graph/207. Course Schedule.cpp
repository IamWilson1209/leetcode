class Solution {
  public:
      bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          /* 有閉環代表不能完成 */
          unordered_map<int, vector<int>> pre_map;
          vector<int> visited(numCourses, 0);
  
          /* 先用map儲存<course, pre(陣列)> */
          for (vector<int> prerequisite : prerequisites) {
              pre_map[prerequisite[0]].push_back(prerequisite[1]);
          }
  
          // 對每門課檢查是否有閉環
          for (int course = 0; course < numCourses; course++) {
              if (visited[course] == 0) { // 只對未訪問的課程啟動 dfs
                  if (!dfs(pre_map, visited, course)) {
                      return false; // 發現閉環
                  }
              }
          }
          return true; // 無環，可完成
      }
  private:
      // dfs 返回 true: 該課程及先修課無環; false: 有環
      bool dfs(unordered_map<int, vector<int>>& pre_map, vector<int>& visited, int course) {
          if (visited[course] == 1) return false;  // 訪問中，發現環
          if (visited[course] == 2) return true;   // 已完成，無需重複檢查
  
          visited[course] = 1;  // 標記為訪問中
          for (int pre : pre_map[course]) {  // 檢查所有先修課
              if (!dfs(pre_map, visited, pre)) {
                  return false;  // 先修課有環
              }
          }
  
          visited[course] = 2;  // 標記為已完成
          return true;  // 無環
      }
  };