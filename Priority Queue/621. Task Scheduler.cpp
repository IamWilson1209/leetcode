class Solution {
  public:
      int leastInterval(vector<char>& tasks, int n) {
          vector<int> count(26, 0); // 紀錄每個任務的數量
          priority_queue<int, vector<int>, less<>> canDo; // 目前可執行任務
          queue<pair<int, int>> coldDown; // 冷卻中任務 {剩餘執行次數, 下次可執行時間}
          int timespan = 0; // 總生命週期
  
          // 紀錄每個任務數量
          for (char task : tasks) {
              count[task - 'A']++;
          }
  
          // 將當前可執行任務推入最大堆
          for (int i = 0; i < 26; i++) {
              if (count[i] > 0) canDo.push(count[i]);
          }
  
          // 模擬CPU週期
          while (!canDo.empty() || !coldDown.empty()) {
              timespan++;
              // 如果沒有任務可執行但有任務在冷卻
              if (canDo.empty()) {
                  // 跳到該任務時間
                  timespan = coldDown.front().second;
              } else {
                  // 如果有任務可執行
                  // 執行目前剩餘次數最多的任務
                  int cnt = canDo.top() - 1;
                  canDo.pop();
                  // 如果還有剩餘任務，推入冷卻時間queue
                  if (cnt > 0) coldDown.push({cnt, timespan + n});
              }
              // 檢查有沒有任務解除冷卻
              if (coldDown.front().second == timespan) {
                  // 有的話推入最大堆
                  canDo.push(coldDown.front().first);
                  coldDown.pop();
              }
          
          }
          // 回傳timespan
          return timespan;
      }
  };