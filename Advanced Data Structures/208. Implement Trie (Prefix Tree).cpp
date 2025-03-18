class TrieNode {
  public:
      // root->is_word
      // root->children[...]
      // 每個children都是TrieNode
      bool is_word; // 表示從根節點到當前節點的路徑是否組成一個完整的單詞
      TrieNode* children[26]; // 大小為 26 的指標陣列，對應小寫字母 'a' 到 'z'。每個元素指向下一個字符的節點
  
      TrieNode() {
          is_word = false;
          for (int i = 0; i < 26; i++) {
              children[i] = NULL;
          }
      }
  };
  
  class Trie {
  private: 
      // 成員變數，生命週期等同於物件生命
      TrieNode* root;
  public:
      Trie() { 
          // TrieNode* root = new TrieNode() 在建構函數內定義了一個局部變數 root
          root = new TrieNode();
      }
  
      void insert(string word) {
          TrieNode* cur = root; // **保護根節點不被修改，不然root會停在別的地方**
          int word_length = word.length();
          int idx = 0;
  
          /*
              'c' (索引 2) -> 創建節點 -> 移動到 'c' 節點
              'a' (索引 0) -> 創建節點 -> 移動到 'a' 節點
              't' (索引 19) -> 創建節點 -> 移動到 't' 節點
          */
          for (int i = 0; i < word_length; i++) {
              idx = word[i] - 'a';
              if (cur->children[idx] == NULL) {   // 1. 如果該字符的子節點不存在
                  cur->children[idx] = new TrieNode(); // 2. 創建新節點
              }
              cur = cur->children[idx]; // 3. 移動到下一個節點
          }
          cur->is_word = true; // 將 't' 節點的 is_word 設為 true
      }
  
      bool search(string word) {
          TrieNode* cur = root; 
          int word_length = word.length();
          int idx = 0;
  
          for (int i = 0; i < word_length; i++) {
              idx = word[i] - 'a';
              cur = cur->children[idx];
              if (cur == NULL) return false; // 如果路徑中斷
          }
  
          return cur->is_word; // 檢查是否為完整單詞
      }
  
      bool startsWith(string prefix) {
          TrieNode* cur = root; 
          int prefix_length = prefix.length();
          int idx = 0;
  
          for (int i = 0; i < prefix_length; i++) {
              idx = prefix[i] - 'a';
              cur = cur->children[idx];
              if (cur == NULL) return false; // 如果路徑中斷
          }   
  
          return true;             
      }
  };
  
  /**
   * Your Trie object will be instantiated and called as such:
   * Trie* obj = new Trie();
   * obj->insert(word);
   * bool param_2 = obj->search(word);
   * bool param_3 = obj->startsWith(prefix);
   */