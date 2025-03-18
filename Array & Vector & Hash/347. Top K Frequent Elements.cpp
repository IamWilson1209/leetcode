class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /* 1.map<數字，次數>、vector<int> ans */
        unordered_map<int, int> count;
        /* for loop all nums, insert into map */
        for (int num : nums) {
            count[num]++;
        }
        /* min priority queue */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto& iter : count) {
            pq.push({iter.second, iter.first}); // 按頻率，對換位置
            /* 如果最大堆積超過k，pop掉最小的*/
            if (pq.size() > k) {
                pq.pop();
            }
        }


        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }    
        return ans;
    }
};
