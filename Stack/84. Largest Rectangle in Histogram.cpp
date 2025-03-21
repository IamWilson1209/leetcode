class Solution {
  public:
      int largestRectangleArea(vector<int>& heights) {
          // num of heights
          int numHeights = heights.size();
  
          // stack: 由底到頂遞減
          stack<int> record;
  
          // vector: leftSmall: 紀錄以heigihts i為高度的矩形，從i開始往左最遠起點，沒有設為0
          vector<int> leftSmall(numHeights);
          
          // vector: rightSmall: 紀錄以heigihts i為高度的矩形，從i開始往右最遠終點，沒有設為numHeights-1
          vector<int> rightSmall(numHeights);
          
          // maxHeight: ans
          int maxHeight = 0;
  
          // 找leftsmall
          for (int height = 0; height < numHeights; height++) {
              // 不為空且stack紀錄的高度大於當前高度
              while (!record.empty() && heights[record.top()] >= heights[height]) record.pop(); // pop出比當前更大的
              if (record.empty()) leftSmall[height] = 0;
              else {
                  leftSmall[height] = record.top() + 1; 
              }
              record.push(height); // 推入的是index
          }
  
          // 清除stack
          while(!record.empty()) record.pop();
  
          // 找rightSmall
          for (int height = numHeights - 1; height >= 0; height--) {
              // 不為空且stack紀錄的高度大於當前高度
              while (!record.empty() && heights[record.top()] >= heights[height]) record.pop(); // pop出比當前更大的
              if (record.empty()) rightSmall[height] = numHeights - 1;
              else {
                  rightSmall[height] = record.top() - 1; 
              }
              record.push(height); // 推入的是index
          }        
  
          // 計算最大結果
          for (int i = 0; i < numHeights; i++) {
              maxHeight = max(maxHeight, (rightSmall[i] - leftSmall[i] + 1) * heights[i]);
          }
  
          // 回傳
          return maxHeight;
      }
  };