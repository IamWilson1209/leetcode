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
      unordered_map<int, int> myMap;
      TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          if (inorder.empty()) return nullptr;
          int n = inorder.size();
          int postIndex = postorder.size() - 1;
          for (int i = 0; i < n; i++) {
              myMap[inorder[i]] = i;
          }
          return build(inorder, postorder, 0, n-1, postIndex);
      }
      TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex) {
          if (inStart>inEnd) {
              return nullptr;
          }
          int val = postorder[postIndex];
          postIndex--;
          TreeNode* root = new TreeNode(val);
  
          int inorderIdx = myMap[val];
          
          root -> right = build(inorder, postorder, inorderIdx + 1, inEnd, postIndex);
          root -> left = build(inorder, postorder, inStart, inorderIdx - 1, postIndex);
          return root;
      }
  };