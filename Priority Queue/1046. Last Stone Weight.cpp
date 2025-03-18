class Solution {
  public:
      int lastStoneWeight(vector<int>& stones) {
          priority_queue<int, vector<int>, less<>> maxHeap;
          for (int stone : stones) {
              maxHeap.push(stone);
          }
  
          while (maxHeap.size() > 1) {
              int heaviest = maxHeap.top();
              maxHeap.pop();
              int secondHeaviest = maxHeap.top();
              maxHeap.pop();
              int newStone = abs(heaviest - secondHeaviest);
              if (newStone != 0) {
                  maxHeap.push(newStone);
              }
          }
  
          return maxHeap.size() == 0 ? 0 : maxHeap.top();
      }
  };
  