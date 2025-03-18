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
      int goodNodes(TreeNode* root) {
          int numGoodNode = 0;
          countGoodNode(root, -101, numGoodNode);
          return numGoodNode;
      }
      void countGoodNode(TreeNode* root, int lowerBound, int& numGoodNode) {
          if (!root) return;
          if (root->val >= lowerBound) {
              numGoodNode++;
              lowerBound = root->val;
          }
          countGoodNode(root->left, lowerBound, numGoodNode);
          countGoodNode(root->right, lowerBound, numGoodNode);
      }
  };
  