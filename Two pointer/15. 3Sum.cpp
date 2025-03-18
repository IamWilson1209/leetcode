class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // 排序，讓雙指針更高效
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            // 雙指針
            // for loop: 每次固定一個，已經找過的會自動被loop過去
            for (int cur = 0; cur < nums.size(); cur++) {
                // 已經排序過，如果跑到正值，後面加起來一定大於0
                // 跳過已經找過且同樣的元素避免重複
                if (cur > 0 && nums[cur] == nums[cur - 1]) {
                    continue;
                }
    
                // start: cur + 1; end: nums.size();
                int start = cur + 1;
                int end = nums.size() - 1;
    
                // while loop: 
                while (start < end) {
                    // 已排序，用類似binary search的概念查找
                    if (nums[cur] + nums[start] + nums[end] > 0) {
                        end--;
                    } else if (nums[cur] + nums[start] + nums[end] < 0) {
                        start++;
                    } else {
                        // 找到一組解
                        ans.push_back({nums[cur], nums[start], nums[end]});
                        start++;
    
                        // **找到一組解後跳過一樣的**
                        while (nums[start] == nums[start - 1] && start < end) {
                            start++;
                        }
                    }
                }
            }
    
            return ans;
        }
    };