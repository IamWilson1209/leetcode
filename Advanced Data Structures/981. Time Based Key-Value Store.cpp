class TimeMap {
  private:
      // 使用 map（而不是 unordered_map）作為內層容器
      // 是因為它會自動按時間升序排序
      // 因為需要考慮順序性所以用map
      unordered_map<string, map<int, string>> tmap;
  public:
      TimeMap() {
          
      }
      
      void set(string key, string value, int timestamp) {
          tmap[key][timestamp] = value;
          // tmap[key].insert({timestamp, value});
      }
      
      string get(string key, int timestamp) {
          // 查找第一個大於 timestamp 的鍵值對
          // {"foo" -> {1 -> "bar", 3 -> "baz"}}
          // get("foo", 2)
          // upper_bound(2) 返回指向 3 -> "baz" 的迭代器
          auto it = tmap[key].upper_bound(timestamp);
          // 檢查 it 是否等於內層 map 的開頭。
          // 如果是，timestamp 比所有現有的時間都小，沒有可用值
          // 如果 it 不是開頭，prev(it) 返回前一個迭代器（即不大於 timestamp 的最大時間戳記）。
          return it == tmap[key].begin() ? "" : prev(it)->second;
      }
  };
  
  
  /**
   * Your TimeMap object will be instantiated and called as such:
   * TimeMap* obj = new TimeMap();
   * obj->set(key,value,timestamp);
   * string param_2 = obj->get(key,timestamp);
   */