/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
      vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
          vector<int> ans;
          unordered_map<int, TreeNode*> parent; /* node->val, parent of node */
          queue<TreeNode*> q;
          q.push(root);
  
          /* 紀錄父節點的BFS */
          while (!q.empty()) {
              int level = q.size();
              for (int i = 0; i < level; i++) {
                  auto top = q.front();
                  q.pop();
  
                  /* 如果有左子樹，紀錄左子樹與當前節點的父子關係 */
                  if (top->left) {
                      parent[top->left->val] = top;
                      q.push(top->left);
                  }
  
                  /* 如果有右子樹，紀錄右子樹與當前節點的父子關係 */
                  if (top->right) {
                      parent[top->right->val] = top;
                      q.push(top->right);
                  }
              }
          }
  
          unordered_map<int, int> visited;
          q.push(target);
          /* BFS 以 target 為出發點向左子樹、右子樹、父節點擴散 k 次 */
          while (k-- && !q.empty()) {
              int size = q.size();
              
              for (int i = 0; i < size; i++) {
                  auto top = q.front();
                  q.pop();
  
                  /* 紀錄當前節點已經走過 */
                  visited[top->val] = 1;
  
                  /* 如果有左子樹，且左子樹沒被走過，下一次BFS走這個節點 */
                  if (top->left && !visited[top->left->val]) {
                      q.push(top->left);
                  }
  
                  /* 如果有右子樹，且右子樹沒被走過，下一次BFS走這個節點 */
                  if (top->right && !visited[top->right->val]) {
                      q.push(top->right);
                  }
  
                  /* 如果有parent，且parent沒被走過，下一次BFS走這個節點 */
                  if (parent[top->val] && !visited[parent[top->val] -> val]) {
                      q.push(parent[top->val]);
                  }
              }
          }
  
          while(!q.empty()) {
              ans.push_back(q.front()->val);
              q.pop();
          }
          return ans;
      }
  };