class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            /* declare map and answer vector */
            unordered_map<int, int> search_map;
            vector<int> ans;
            int size = nums.size();
            /* for loop nums */
            for (int index = 0; index < size; index++) {
                int complement = target - nums[index];
                /* 
                    map[key] = value
                    find() search for "key"
                */
                if (search_map.find(complement) != search_map.end()) {
                    /* insert complement's index */
                    ans.push_back(search_map[complement]);
                    /* insert current index */
                    ans.push_back(index);
                    return ans;
                } else {
                    /* if not found，insert current num to key */
                    search_map[nums[index]] = index;
                }               
            }
            return ans;
        }
    };