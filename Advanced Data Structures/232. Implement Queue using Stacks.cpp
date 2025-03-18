class MyQueue {
  private:
      stack<int> st1;
      stack<int> st2;
  
  public:
      MyQueue() {}
  
      void push(int x) { st1.push(x); }
  
      int pop() {
          if (st2.empty()) { // 如果 st2 為空，將 st1 的元素轉移到 st2
              while (!st1.empty()) {
                  int x = st1.top();
                  st1.pop();
                  st2.push(x);
              }
          }
          // 此時 st2 不為空，直接從 st2 彈出
          int temp = st2.top();
          st2.pop();
          return temp;
      }
  
      int peek() {
          if (st2.empty()) { // 如果 st2 為空，將 st1 的元素轉移到 st2
              while (!st1.empty()) {
                  int x = st1.top();
                  st1.pop();
                  st2.push(x);
              }
          }
          // 此時 st2 不為空，直接返回頂部元素
          return st2.top();
      }
  
      bool empty() { return st1.empty() && st2.empty(); }
  };
  
  /**
   * Your MyQueue object will be instantiated and called as such:
   * MyQueue* obj = new MyQueue();
   * obj->push(x);
   * int param_2 = obj->pop();
   * int param_3 = obj->peek();
   * bool param_4 = obj->empty();
   */