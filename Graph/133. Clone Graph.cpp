/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    public:
        /*map紀錄是否走過<原本node, copy node>*/
        unordered_map<Node*, Node*> map;
        Node* cloneGraph(Node* node) {
            /* Init condition */
            if (node == nullptr)
                return nullptr;
                    /*dfs(Node* node)*/
                    dfs(node);
            /*return new Graph Node*/
            return map[node];
        }
        void dfs(Node* node) {
            /*declare new node*/
            Node* copy = new Node(node->val);
            /*放到 map*/
            map[node] = copy;
            /*檢查此節點的所有鄰居節點*/
            for (auto neighbor: node->neighbors) {
                if (map.find(neighbor) != map.end()) {
                    /* 
                        如果鄰居已經在map中，代表不用再找
                        直接push進此節點的鄰居節點
                    */
                    copy->neighbors.push_back(map[neighbor]);
                } else {
                    /* 
                        如果map找不到鄰居節點
                        先dfs此鄰居
                        存完之後push_back此鄰居
                    */
                    dfs(neighbor);
                    copy->neighbors.push_back(map[neighbor]);
                }
            }
        }
    };