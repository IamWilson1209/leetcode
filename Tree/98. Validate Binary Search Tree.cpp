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
      bool isValidBST(TreeNode* root) { return solution(root, nullptr, nullptr); }
  
  private:
      bool solution(TreeNode* node, TreeNode* lowerBound, TreeNode* upperBound) {
          // 如果是空值，回傳true
          if (node == nullptr)
              return true;
          // 如果目前節點小於lowerbound，不符合
          if (lowerBound != nullptr && node->val <= lowerBound->val)
              return false;
          // 如果目前節點大於upperbound，不符合
          if (upperBound != nullptr && node->val >= upperBound->val)
              return false;
          // 左樹：lowerbound維持, upper更新為目前節點，因為父節點一定比原upper小
          // 右樹：upperbound維持, lower更新為目前節點，因為父節點一定比原lower大
          return solution(node->left, lowerBound, node) &&
                 solution(node->right, node, upperBound);
      }
  };