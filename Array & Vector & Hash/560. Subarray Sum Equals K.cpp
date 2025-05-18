class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> subNum; // 哈希表，<前綴和, 出現次數>
        subNum[0] = 1; // 初始化：前綴和為 0 出現 1 次
        int total = 0, ans = 0; // total: 當前前綴和, count: 滿足條件的子陣列數量

        for (int n : nums) {
            total += n;

            /* 有沒有某個之前的點，total 比現在少 k（即 total - k）？如果是，從那個點到現在的點的 sum 就是 k */
            if (subNum.find(total - k) != subNum.end()) {
                ans += subNum[total - k]; // 累加符合條件的子陣列數
            }

            subNum[total]++;
        }

        return ans;
    }
};