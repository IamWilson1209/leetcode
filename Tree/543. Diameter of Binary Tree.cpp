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
      int diameterOfBinaryTree(TreeNode* root) {
          int max_diameter = 0;
          diameter(root, max_diameter);
          return max_diameter;
      }
  private:
      int diameter(TreeNode* root, int& max_diameter) {
          if (!root) return 0;
          // 遞迴計算左右子樹最長路徑
          int left = diameter(root->left, max_diameter);
          int right = diameter(root->right, max_diameter);
          // 當前節點的最長路徑可能是左子樹高度 + 右子樹高度
          // 更新最長路徑
          max_diameter = max(max_diameter, left + right);
          // 回傳目前height
          return max(left, right) + 1;
      }
  };
  