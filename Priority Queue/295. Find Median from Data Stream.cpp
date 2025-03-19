class MedianFinder {
  private:
     priority_queue<int> maxHeap; // 小數部分
     priority_queue<int, vector<int>, greater<int>> minHeap; // 大數部分
  public:
      MedianFinder() {
      }
      
      void addNum(int num) {
          if (maxHeap.empty() || num < maxHeap.top()) {
              // 預設是塞在maxHeap，
              // num小於較小一邊最大的數字
              maxHeap.push(num); 
          } else {
              minHeap.push(num);
          }
  
          // 平衡堆大小
          // maxHeap 可以比 minHeap 多存一個
          if (maxHeap.size() > minHeap.size() + 1) {
              minHeap.push(maxHeap.top());
              maxHeap.pop();
          } else if (minHeap.size() > maxHeap.size()) {
              maxHeap.push(minHeap.top());
              minHeap.pop();
          }
      }
      
      double findMedian() {
          if (maxHeap.size() == minHeap.size()) {
              return (maxHeap.top() + minHeap.top()) / 2.0;
          }
          return maxHeap.top();
      }
  };
  
  /**
   * Your MedianFinder object will be instantiated and called as such:
   * MedianFinder* obj = new MedianFinder();
   * obj->addNum(num);
   * double param_2 = obj->findMedian();
   */