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
      int max_sum;
      int maxPathSum(TreeNode* root) {
          max_sum = INT_MIN;
          maxPath(root);
          return max_sum;
      }
      int maxPath(TreeNode* node) {
          // 若為空，回傳0
          if (!node) return 0;
  
          // 計算左右子樹的最大路徑和
          // 如果結果為負，取0（不包含該路徑）
          int left_sum = max(0, maxPath(node->left));
          int right_sum = max(0, maxPath(node->right));
  
          // 更新全局最大值，考慮當前節點值加上左右子樹的和
          max_sum = max(max_sum, node->val + left_sum + right_sum);
  
          /*  
              node->val + left + right 是一個「彎折」路徑，
              只能作為一個完整的路徑候選，不可以被上層再利用
              node->val + left + right 的情況已經在 
              max_sum = max(max_sum, node->val + left + right) 中被考慮過，
              用來更新全局最大值，但不適合作為返回值。 
          */
          // 返回給上一層的最大單邊路徑（選左或右）
          return node->val + max(left_sum, right_sum);
      }
  };