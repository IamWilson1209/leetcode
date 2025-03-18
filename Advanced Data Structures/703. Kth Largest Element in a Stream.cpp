class KthLargest {
  private:
      int numK;
      priority_queue<int, vector<int>, greater<int>> pq;
  public:
      KthLargest(int k, vector<int>& nums) {
          numK = k;
          for (int num : nums) {
              pq.push(num);
              if (pq.size() > k) pq.pop();
          }
      }
      
      int add(int val) {
          pq.push(val);
          // 如果一開始塞的小於k，還是有可能不用pop()
          if (pq.size() > numK) pq.pop();
          return pq.top();
      }
  };
  