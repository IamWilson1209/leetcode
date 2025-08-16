class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;

        int ans = nums[0] + nums[1] + nums[2];
        int minDist = INT_MAX;
        sort(nums.begin(), nums.end());

        for (int cur = 0; cur < nums.size(); cur++) {
            if (cur > 0 && nums[cur] == nums[cur-1]) continue;

            int curNext = cur + 1;
            int end = nums.size() - 1;

            while (curNext < end) {
                int curSum = nums[cur] + nums[curNext] + nums[end];
                if (curSum == target) return curSum;
                if (abs(curSum - target) < minDist) {
                    minDist = abs(curSum - target);
                    ans = curSum;
                }
                if (curSum < target) {
                    curNext++;
                    while (curNext < end && nums[curNext] == nums[curNext-1]) {
                        curNext++;
                    }
                } else {
                    end--;
                    while (curNext < end && nums[end] == nums[end+1]) {
                        end--;
                    }                    
                }
            }
        }

        return ans;
    }
};