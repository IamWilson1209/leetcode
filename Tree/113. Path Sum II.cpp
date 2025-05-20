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
  private: 
      vector<vector<int>> ans;
      vector<int> curAns;
      int curSum = 0;
  public:
      vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
          path(root, ans, curAns, curSum, targetSum);
          return ans;
      }
     void path(TreeNode* node, vector<vector<int>> &ans, vector<int>& curAns, int& curSum, int& targetSum) {
          /* 如果不存在，返回 */
          if (!node) return;
  
          /* 本次計算加總，臨時答案push back */
          curSum += node->val;
          curAns.push_back(node->val);
  
          /* 檢查是否有答案 */
          if (!node->left && !node->right) {
              if (curSum == targetSum) {
                  ans.push_back(curAns);
              }
          }
  
          /* 左右兩邊檢查 */
          path(node->left, ans, curAns, curSum, targetSum);
          path(node->right, ans, curAns, curSum, targetSum);
  
          /* 回溯 */
          curAns.pop_back();
          curSum = curSum - node->val;
      }
  };