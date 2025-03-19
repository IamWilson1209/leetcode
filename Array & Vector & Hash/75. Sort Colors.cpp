class Solution {
  public:
      void sortColors(vector<int>& nums) {
          // 一班的排序不知道元素裡面由什麼
          // 現在知道只有0、1、2
          // 用map
          unordered_map<int, int> colorMap; // 顏色、頻率
          for (int num : nums) {
              colorMap[num]++;
          }
  
          int idx = 0;
          for (int color = 0; color < 3; color++) {
              int freq = colorMap[color];
              for (int j = 0; j < freq; j++) {
                  nums[idx] = color;
                  idx++;
              }
          }
      }
  };