// 定義雙向鏈表的節點結構
class Node {
  public:
      int key;
      int val;
      Node* prev; // 前後指針（prev 和 next）
      Node* next;
      // 初始化列表效率更好
      Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
  };
  
  class LRUCache {
  private:
      int cap;                         // 快取的容量限制
      unordered_map<int, Node*> cache; // 雜湊表，映射鍵（int）到鏈表節點（Node*）
      Node* oldest;                    // 最近最少使用的元素
      Node* latest;                    // 最近使用的元素
  public:
      LRUCache(int capacity) {
          cap = capacity;
          // 創建虛擬頭節點 oldest 和虛擬尾節點 latest
          oldest = new Node(0, 0);
          latest = new Node(0, 0);
          oldest->next = latest;
          latest->prev = oldest;
      }
  
      int get(int key) {
          if (cache.find(key) != cache.end()) {
              Node* node = cache[key];
              remove(node); // 從鏈表中移除該節點（remove）
              insert(node); // 將其插入到最近使用位置（insert）
              return node->val;
          }
          return -1;
      }
      void put(int key, int value) {
          // 如果key已經存在，移除
          if (cache.find(key) != cache.end()) {
              remove(cache[key]);
          }
          // 創建新節點 newNode，更新 cache 映射，
          // 插入到最近使用位置（insert）
          Node* newNode = new Node(key, value);
          cache[key] = newNode;
          insert(newNode);
          // 如果超過容量 cap：移除最近最少使用的節點（oldest->next）
          if (cache.size() > cap) {
              Node* lru = oldest->next;
              remove(lru);
              cache.erase(lru->key); // erase!
              delete lru;
          }
      }
  
  private:
      void remove(Node* node) {
          Node* prevNode = node->prev;
          Node* nextNode = node->next;
          prevNode->next = nextNode;
          nextNode->prev = prevNode;
      }
      void insert(Node* node) {
          // 節點 node 插入到鏈表靠近 latest 虛擬節點的一端（最近使用位置）
          Node* prevNode = latest->prev;
          Node* nextNode = latest;
          // 更新連結node的兩條link
          prevNode->next = node;
          nextNode->prev = node;
          // 更新node出去的兩條link
          node->next = nextNode;
          node->prev = prevNode;
      }
  };
  
  /**
   * Your LRUCache object will be instantiated and called as such:
   * LRUCache* obj = new LRUCache(capacity);
   * int param_1 = obj->get(key);
   * obj->put(key,value);
   */