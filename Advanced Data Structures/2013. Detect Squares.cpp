class DetectSquares {
  public:
      map<pair<int, int>, int>mp; /* 座標、次數 */
      DetectSquares() {
          
      }
      
      void add(vector<int> point) {
          mp[{point[0], point[1]}]++;
      }
      
      int count(vector<int> pt) {
          int count = 0;
          int x = pt[0];
          int y = pt[1];
          /* 對於棋盤上的每個點 */
          for (auto p:mp) {
              pair<int, int> point = p.first;
              /* 檢查 point (x1, y1) 是否可以和 (x, y) 組成正方形的對角線 */
              if (point.first != x && point.second != y && (abs(point.first - x) == abs(point.second - y))) {
                  int f1 = mp[{point.first, point.second}]; /* 點 (x1, y1) 的次數 */
                  int f2 = mp[{point.first, y}]; /* 點 (x1, y) 的次數 */
                  int f3 = mp[{x, point.second}]; /* 點 (x, y1) 的次數 */
                  /* 這三個點的次數相乘，表示可以組成的正方形數量 */
                  count += f1*f2*f3;
              }
          }
          return count;
      }
  };
  
  /**
   * Your DetectSquares object will be instantiated and called as such:
   * DetectSquares* obj = new DetectSquares();
   * obj->add(point);
   * int param_2 = obj->count(point);
   */