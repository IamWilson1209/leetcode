class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
            /*
            在一棵樹中，移除所有leaf後，剩下的子圖仍然是一棵樹
            重複這個過程，最後剩下的 1 或 2 個節點就是樹的中心點
            這些中心點作為根時，樹的高度會是最小的
            */
            if (n == 1)
                return {0}; // 本身就是根，高度為 0
    
            unordered_map<int, vector<int>> biGraph;
            vector<int> degrees(n, 0);
    
            // 無向圖O(無方向) 鄰接表X(有方向)
            for (const auto& edge : edges) {
                int edge1 = edge[0];
                int edge2 = edge[1];
                biGraph[edge1].push_back(edge2);
                biGraph[edge2].push_back(edge1);
                degrees[edge1]++;
                degrees[edge2]++;
            }
    
            // 將所有初始葉節點加入佇列
            queue<int> q;
            for (int edge = 0; edge < n; edge++) {
                if (degrees[edge] == 1)
                    q.push(edge);
            }
    
            int remainNodes = n;
            while (remainNodes > 2) {
                int size = q.size();
                remainNodes -= size;
                // 每個 leaf: 遍歷它的鄰居
                for (int i = 0; i < size; i++) {
                    int leaf = q.front();
                    q.pop();
                    for (int neighbor : biGraph[leaf]) {
                        // 減少鄰居的度數（因為葉節點被移除）
                        // 如果某個鄰居的度數變成 1，它就成為新的葉節點，加入佇列
                        degrees[neighbor]--;
                        if (degrees[neighbor] == 1)
                            q.push(neighbor);
                    }
                }
            }
    
            vector<int> result;
            while (!q.empty()) {
                result.push_back(q.front());
                q.pop();
            }
    
            return result;
        }
    };