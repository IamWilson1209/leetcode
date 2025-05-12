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
    // 建立中序序列的索引映射
    unordered_map<int, int> inorderMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        // 將前序序列轉成隊列，方便pop
        queue<int> preOrderQueue(preorder.begin(), preorder.end());
        return build(preOrderQueue, inorder, inorderMap, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(queue<int>& preOrderQueue, vector<int>& inorder, unordered_map<int, int>& inorderMap, int inorderStart, int inorderEnd) {
        // 遞迴終止條件：子樹範圍為空
        if (inorderStart > inorderEnd) {
            return nullptr;
        }

        // 從前序隊列取根
        TreeNode* node = new TreeNode(preOrderQueue.front());
        preOrderQueue.pop();

        // 根據根值從map中獲取其在中序序列中的索引
        int inorderIndex = inorderMap[node->val];

        // 遞迴建立左子樹和右子樹
        node->left = build(preOrderQueue, inorder, inorderMap, inorderStart, inorderIndex - 1);
        node->right = build(preOrderQueue, inorder, inorderMap, inorderIndex + 1, inorderEnd);

        return node;
    }
};