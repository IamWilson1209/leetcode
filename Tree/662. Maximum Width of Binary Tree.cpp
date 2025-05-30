/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
      int widthOfBinaryTree(TreeNode* root) {
          if (!root)
              return 0;
  
          queue<pair<TreeNode*, unsigned long long>> q; /*<node, position index>*/
          q.push({root, 0});                            /* 推入根節點 */
          int maxWidth = 0;
  
          while (!q.empty()) {
              int levelSize = q.size();
              unsigned long long levelStart = q.front().second; /* start index*/
              unsigned long long levelEnd = q.back().second; /* end index */
              maxWidth = max(maxWidth, (int)(levelEnd - levelStart + 1));
  
              for (int i = 0; i < levelSize; i++) {
                  auto [node, position] = q.front();
                  q.pop();
                  if (node->left)
                      q.push(
                          {node->left,
                           position *
                               2}); /* 如果節點有左子節點，索引為 position * 2 */
                  if (node->right)
                      q.push(
                          {node->right, position * 2 + 1}); /* 如果節點有右子節點，索引為
                                                               position * 2 + 1 */
              }
          }
  
          return maxWidth;
      }
  };