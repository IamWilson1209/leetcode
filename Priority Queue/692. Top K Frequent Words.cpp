class Solution {
  public:
      vector<string> topKFrequent(vector<string>& words, int k) {
          // 建立頻率映射
          unordered_map<string, int> wordDict;
          for (string word : words) {
              wordDict[word]++;
          }
          
          // 使用最大堆
          auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
              // 如果頻率相同，按字典序升序排序
              // 如果頻率不同，按頻率降序排序
              return a.second == b.second ? a.first > b.first : a.second < b.second;
          };
          priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
          
          // 將所有單詞加入最大堆
          for (auto& entry : wordDict) {
              pq.push({entry.first, entry.second});
          }
          
          // 提取前 k 個單詞
          vector<string> result;
          for (int i = 0; i < k && !pq.empty(); i++) {
              result.push_back(pq.top().first);
              pq.pop();
          }
          
          return result;
      }
  };