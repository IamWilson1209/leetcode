/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  public:
      // Encodes a tree to a single string.
      string serialize(TreeNode* root) {
          if (!root) return "";
  
          string treeCode;
          queue<TreeNode*> visited;
          visited.push(root);
  
          while (!visited.empty()) {
              TreeNode* node = visited.front();   
              visited.pop();
  
              if (node) {
                  treeCode += to_string(node->val) + ",";
                  visited.push(node->left);
                  visited.push(node->right);
              } else {
                  treeCode += "N,";
              }
          }
          if (!treeCode.empty()) treeCode.pop_back(); // 移除多一個,
          return treeCode;
      }
  
      // Decodes your encoded data to tree.
      TreeNode* deserialize(string data) {
          if (data.empty()) return nullptr;
  
          vector<string> nodes;
          stringstream ss(data);
          string token;
  
          // 分割字串塞到nodes vector
          while (getline(ss, token, ',')) {
              nodes.push_back(token);
          }
  
          if (nodes[0] == "N") return nullptr;
          TreeNode* root = new TreeNode(stoi(nodes[0]));
          queue<TreeNode*> q;
          q.push(root);
  
          int idx = 1; // 第二個元素開始
          while (!q.empty() && idx < nodes.size()) {
              TreeNode* parent = q.front();
              q.pop();
  
              // 如果左邊不為空(空的話會跳過)
              if (idx < nodes.size() && nodes[idx] != "N") {
                  parent->left = new TreeNode(stoi(nodes[idx]));
                  q.push(parent->left);
              }
              idx++; // 換右邊
  
              // 如果右邊不為空
              if (idx < nodes.size() && nodes[idx] != "N") {
                  parent->right = new TreeNode(stoi(nodes[idx]));
                  q.push(parent->right);
              }
              idx++; // 換下一棵
          }
          return root;
      }
  };
  
  // Your Codec object will be instantiated and called as such:
  // Codec ser, deser;
  // TreeNode* ans = deser.deserialize(ser.serialize(root));