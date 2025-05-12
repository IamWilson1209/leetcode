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
      bool isSubtree(TreeNode* root, TreeNode* subRoot) {
          /* 
              Baseline:
              1. root cannot be null
              2. subRoot can be null
          */
        //   if (subRoot == nullptr) {
        //       return true;
        //   }
          if (root == nullptr) {
              return false;
          }
          /* Pass baseline(Both not null): start the validation */
          if (isSub(root, subRoot)) {
              return true;
          }
          /* Not null but not same: check subtree */
          return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
      }
  private:
      bool isSub(TreeNode* root, TreeNode* subRoot) {
          /* Baseline: root && subroot == null */
          if (root == nullptr && subRoot == nullptr) {
              return true;
          }
          /* Not null for one side: return fase */
          if (root == nullptr || subRoot == nullptr) {
              return false;
          }
          /* Same: start compare */
          if (root->val == subRoot->val) {
              return isSub(root->left, subRoot->left) && 
              isSub(root->right, subRoot->right);
          }
          /* Not same: return false */
          return false;
      }
  };