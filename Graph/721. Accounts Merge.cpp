class Solution {
  public:
      vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
          unordered_map<string, vector<string>> biGraph;
          unordered_map<string, int> visited;
          int n = accounts.size();
  
          // build bidirectional graph
          /*
              ["John", "email1", "email2", "email3"]
              變成
              biGraph["email1"] = ["email2", "email3"]
              biGraph["email2"] = ["email1"]
              biGraph["email3"] = ["email1"]            
          */
          for (auto &account : accounts) {
              string firstEmail = account[1];
              for (int email = 2; email < account.size(); email++) {
                  biGraph[firstEmail].push_back(account[email]);
                  biGraph[account[email]].push_back(firstEmail);
              }
          }
  
          vector<vector<string>> ans;
  
          // 對每個firstEmail 做 DFS
          for (auto& account : accounts) {
              string name = account[0];
              string firstEmail = account[1];
  
              // 如果第一封email還沒被訪問過
              if (!visited[firstEmail]) {
                  vector<string> temp;
                  temp.push_back(name);
                  dfs(temp, firstEmail, visited, biGraph);
                  // 按照排序塞到ans
                  sort(temp.begin() + 1, temp.end());
                  ans.push_back(temp);
              }
          }
          return ans;
      }
      void dfs (vector<string>& temp, string firstEmail, unordered_map<string, int>& visited, unordered_map<string, vector<string>>& biGraph) {
          visited[firstEmail] = 1;
          temp.push_back(firstEmail); // 相鄰的email都push進目前在處理的vector
          // 遍歷biGraph裡此firstEmail的所有鄰接點email
          for (auto it : biGraph[firstEmail]) {
              if (!visited[it]) {
                  dfs(temp, it, visited, biGraph);
              }
          }
      }
  };