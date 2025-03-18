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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            /* 都是 null */
            if (p == nullptr && q == nullptr) return true;
            /* 其一為 null */
            if (p == nullptr || q == nullptr) return false;
            /* 都不為null */
            return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    };