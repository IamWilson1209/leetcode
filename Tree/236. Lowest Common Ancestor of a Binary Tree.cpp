/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          return LCA(root, p, q);        
      }
  private: 
      TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
  
          if (root == nullptr) return nullptr;
  
          if (root->val == p->val || root->val == q->val)  {
              return root; // 一邊找到
          }
          TreeNode* left = LCA(root->left, p, q);
          TreeNode* right = LCA(root->right, p, q);
  
          if (left && right) {
              return root; // 兩邊都找到
          }
          return left == nullptr ? right : left; // 代表一定有一邊是空，另一邊找到答案，回傳非空的那邊
      }
  };