class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        /* 如果 hand 的大小無法被 groupSize 整除，則無法分組 */        
        if (hand.size() % groupSize != 0) {
            return false;
        }

        /* 使用 map 統計每個數字的頻次，方便處理重複數字 */
        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        /* 使用小頂堆來存儲當前可用的最小數字, 每個數字只存一次 */
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [card, count] : freq) {
            if (count > 0) {
                pq.push(card);
            }
        }

        /* 按 groupSize 分組 */
        while (!pq.empty()) {
            int start = pq.top(); // 當前組的起始數字
            vector<int> toRemove; // 記錄需要從 pq 移除的數字
            toRemove.push_back(start);

            // 檢查連續的 groupSize 個數字
            for (int i = 0; i < groupSize; i++) {
                if (freq[start + i] == 0) { // 如果當前數字不存在或數量不足
                    return false;
                }
                freq[start + i]--; // 減少該數字的頻次
                // 如果數字用完要移除
                if (freq[start + i] == 0) {
                    // 如果 pq.top() < start + i
                    // 說明存在更小的數字（例如 pq.top()）
                    // 無法按照正確的順序組成連續序列，因此返回 false
                    if (pq.top() != start + i) { 
                        return false;
                    }
                    pq.pop(); // 移除用完的數字
                }
            }
        }

        // 如果所有數字都成功分組，返回 true
        return true;
    }
};

/*
    初始化：
        freq = {1:1, 2:2, 3:2, 4:1, 6:1, 7:1, 8:1}
        pq = [1, 2, 3, 4, 6, 7, 8]
    第一組（start = 1）：
        檢查 [1,2,3]：
        freq[1] = 1 > 0，減到 0，檢查 pq.top() = 1（匹配），移除 1。
        freq[2] = 2 > 0，減到 1，不移除。
        freq[3] = 2 > 0，減到 1，不移除。
        堆變為 [2, 3, 4, 6, 7, 8]。
    第二組（start = 2）：
        檢查 [2,3,4]：
        freq[2] = 1 > 0，減到 0，檢查 pq.top() = 2（匹配），移除 2。
        freq[3] = 1 > 0，減到 0，檢查 pq.top() = 3（匹配），移除 3。
        freq[4] = 1 > 0，減到 0，檢查 pq.top() = 4（匹配），移除 4。
        堆變為 [6, 7, 8]。
*/