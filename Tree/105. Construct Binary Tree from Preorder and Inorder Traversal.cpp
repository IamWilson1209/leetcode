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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            queue<int> pre_order_queue(preorder.begin(), preorder.end());
            return build(pre_order_queue, inorder);
    
        }
        // pre: 按照順序就可以遞迴建立子樹: <-[3, 9, 20, 15, 7]<-
        // in: 可以看出左右子樹：[9(左), "3", (右)15, 20, 7]、[15(左), 20, (右)7]
        TreeNode* build(queue<int>& pre_order_queue, vector<int>& inorder) {
            // 遞迴終止條件，子樹為空
            if (!inorder.empty()) {
                
                // 更新當前節點
                TreeNode* node = new TreeNode();
                node->val = pre_order_queue.front();
                pre_order_queue.pop();
    
                // 更新位址
                auto iter = find(inorder.begin(), inorder.end(), node->val);
                int inorder_index = iter - inorder.begin();
    
                // 更新左右子樹inorder向量
                vector<int> left_tree(inorder.begin(), inorder.begin() + inorder_index);
                vector<int> right_tree(inorder.begin() + inorder_index + 1, inorder.end());
    
                // 建立node的左、右子樹，好了之後回傳建立好的node子樹
                node->left = build(pre_order_queue, left_tree);
                node->right = build(pre_order_queue, right_tree);
                return node;
            }
            return nullptr;
        }
    };