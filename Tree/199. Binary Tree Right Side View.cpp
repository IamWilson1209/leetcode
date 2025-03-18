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
      vector<int> rightSideView(TreeNode* root) {
          if (!root) return {};
          vector<int> ans;
          queue<TreeNode*> visited;
  
          // bfs
          visited.push(root);
          while (!visited.empty()) {
              int levelLength = visited.size();
              for (int i = 0; i < levelLength; i++) {
                  TreeNode* node = visited.front();
                  if (node->left) visited.push(node->left);
                  if (node->right) visited.push(node->right);
                  if (i == levelLength - 1) {
                      ans.push_back(node->val);
                  }
                  visited.pop();
              }
          }
          return ans;
      }
  };
  