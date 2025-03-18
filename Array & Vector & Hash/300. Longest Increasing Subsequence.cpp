class Solution {
  public:
      int lengthOfLIS(vector<int>& nums) {
          vector<int> sub; // 模擬遞增序列
          for (int num : nums) {
              // 如果 sub 空的，或 num 比最後一個數字大，就塞進去
              if (sub.empty() || sub[sub.size() - 1] < num) {
                  sub.push_back(num);
              } else {
                  // 找到第一個 >= num 的位置
                  auto iter = lower_bound(sub.begin(), sub.end(), num);
                  if (iter != sub.end()) *iter = num; // 把那個位置的數字換成 num
              }
          }
          return sub.size();
      }
  };