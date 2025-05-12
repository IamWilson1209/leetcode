class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int maxLength = 0;

        /* 
            如果某個 sum 在不同位置出現兩次，說明這兩個位置之間的子陣列和是 0 
            index i時: sum[i]是index 0到i的和
            index j時: sum[j]是index 0到j的和
            如果sum[i] = sum[j] = k，表示從 i+1 到 j 的子陣列和是：
            sum[j] - sum[i] = k - k = 0;
        */
        unordered_map<int, int> seen{{ 0, -1 }}; /* <sum值, 這個sum第一次出現的開始index> */

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;
            /* 檢查這個sum有沒有被記錄過 */
            if (seen.count(sum)) maxLength = max(maxLength, i - seen[sum]);
            else seen[sum] = i;
        }

        return maxLength;
    }
};