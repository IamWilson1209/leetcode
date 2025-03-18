/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
      vector<vector<int>> levelOrder(TreeNode* root) {
          if (!root) return {};
          queue<TreeNode*> q;
          vector<vector<int>> ans;
          bfs(root, q, ans);
          return ans;
      }
  private:
      void bfs(TreeNode* node, queue<TreeNode*> q, vector<vector<int>>& ans) {
          q.push(node);
          while (!q.empty()) {
              int curr_level_node_num = q.size();
              vector<int> temp;
              for (int i = 0; i < curr_level_node_num; i++) {
                  TreeNode* tn = q.front();
                  temp.push_back(tn->val);
                  q.pop();
  
                  if (tn->left) q.push(tn->left);
                  if (tn->right) q.push(tn->right);
              }
              ans.push_back(temp);
          }
      }
  };