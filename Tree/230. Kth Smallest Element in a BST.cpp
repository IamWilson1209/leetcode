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
      int kthSmallest(TreeNode* root, int k) {
          priority_queue<int, vector<int>, greater<>> pq;
          find_smallest(root, k, pq);
          for (int i = 0; i < k - 1; i++) {
              pq.pop();
          }
          return pq.top();
      }
      void find_smallest(TreeNode* node, int k, priority_queue<int, vector<int>, greater<>>& pq) {
          if (node->left != nullptr) find_smallest(node->left, k, pq);
          pq.push(node->val);
          if (node->right != nullptr) find_smallest(node->right, k, pq);
      }
  };


class Solution {
  public:
      int kthSmallest(TreeNode* root, int k) {
          vector<int> ans;
          getKsmallest(root, k, ans);
          for (int i = 0; i < ans.size(); i++) {
              cout << ans[i] << endl;
          }
          return ans[k-1];
      }
      void getKsmallest(TreeNode* root, int k, vector<int>& ans) {
          if (root->left != nullptr) getKsmallest(root->left, k, ans);
          ans.push_back(root->val);
          if (root->right != nullptr) getKsmallest(root->right, k, ans);
      }
  };
  
  class Solution {
    public:
        int kthSmallest(TreeNode* root, int k) {
            int count = 0, result = 0; // count 目前記錄的多少node
            inorder(root, k, count, result);
            return result;
        }
        void inorder(TreeNode* node, int k, int& count, int& result) {
            // 檢查，Baseline
            if (!node || count >= k) return;
            // 左
            inorder(node->left, k, count, result);
            // 中
            count++;
            if (count == k) {
                result = node->val;
                return;
            }
            // 右
            inorder(node->right, k, count, result);
        }
    };