class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            // declare answer
            int ans = INT_MIN;
    
            // declare product
            int product = 1;
    
            /*
                第一次從左到右：捕捉從陣列開始位置到某個點的最大乘積
                第二次從右到左：捕捉從陣列結束位置到某個點的最大乘積
            */
            // calculate max product from left
            for (int i = 0; i < nums.size(); i++) {
                product *= nums[i];
                // 更新ans
                if (product > ans) ans = product;
                // 重置
                if (product == 0) product == 1;
            }
    
            product = 1;
            // calculate max product from left
            for (int i = nums.size() - 1; i >= 0; i--) {
                product *= nums[i];
                // 更新ans
                if (product > ans) ans = product;
                // 重置
                if (product == 0) product == 1;
            }
    
            return ans;
    
        }
    };