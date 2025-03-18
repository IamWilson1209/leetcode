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
      int maxDepth(TreeNode* root) {
          if (root == nullptr) return 0;
          return max(maxDepth(root->right), maxDepth(root->left)) + 1;
      }
  };

 class Solution {
    public:
        int maxDepth(TreeNode* root) {
            int max_height = 0;
            dfs(root, 0, max_height);
            return max_height;
        }
        void dfs(TreeNode* node, int cur_height, int& max_height) {
            if (!node) return;
            max_height = max(max_height, cur_height+1);
            if (node->left) dfs(node->left, cur_height+1, max_height);
            if (node->right) dfs(node->right, cur_height+1, max_height);
        }
    };
    