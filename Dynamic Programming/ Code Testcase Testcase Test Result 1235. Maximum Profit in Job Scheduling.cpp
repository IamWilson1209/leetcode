class Solution {
  public:
      int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
          int totalJobs = startTime.size();
          vector<vector<int>> jobs;
          vector<int> dp(totalJobs, -1); // dp[i] 表示從第 i 個工作開始到最後所能獲得的最大利潤
  
          // 將job資訊放入二維陣列jobs
          for (int job = 0; job < totalJobs; job++) {
              jobs.push_back({startTime[job], endTime[job], profit[job]});
          }
  
          // 排序jobs，根據startTime
          sort(jobs.begin(), jobs.end());
  
          // 排序startTime
          sort(startTime.begin(), startTime.end());
  
          // 回傳結果
          return find(0, jobs, startTime, totalJobs, dp);
      }
      // 找到現在這個job結束，下一個job開始後的的最大收益
      int find(int idx, vector<vector<int>>& jobs, vector<int>& startTime, int& totalJobs, vector<int>& dp) {
          if (idx >= totalJobs) return 0;
          if (dp[idx] != -1) return dp[idx]; // 從dp[i]開始的最大利潤計算過
  
          // 找第一個開始時間大於這個job結束時間的job index
          int nextIdx = lower_bound(startTime.begin(), startTime.end(), jobs[idx][1]) - startTime.begin();
  
          // 選或不選
          int pick = jobs[idx][2] + find(nextIdx, jobs, startTime, totalJobs, dp); // 選profit+選完下一個max profit
          int notPick = find(idx+1, jobs, startTime, totalJobs, dp); // 不選跳下一個job
          return dp[idx] = max(pick, notPick); // 取選或不選最大的
      }
  };