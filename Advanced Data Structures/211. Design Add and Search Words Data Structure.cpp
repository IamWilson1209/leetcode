class TrieNode {
  public:
      bool is_word;
      TrieNode* children[26];
      TrieNode() {
          is_word = false;
          for (int i = 0; i < 26; i++) {
              children[i] = NULL;
          }
      }
  };
  
  class WordDictionary {
  private:
      TrieNode* root;
  
  public:
      WordDictionary() { 
          root = new TrieNode(); 
      }
  
      void addWord(string word) {
          int word_len = word.length();
          TrieNode* cur = root;
          for (char c : word) {
              int idx = c - 'a';
              if (!cur->children[idx])
                  cur->children[idx] = new TrieNode();
              cur = cur->children[idx];
          }
          cur->is_word = true;
      }
  
      bool search(string word) { return search_helper(word, 0, root); }
  
  private:
      bool search_helper(string word, int pos, TrieNode* node) {
          // 達到末尾，檢查是不是單字
          if (pos == word.length()) {
              return node->is_word;
          }
  
          // 如果是"."，嘗試所有子節點
          if (word[pos] == '.') {
              for (int i = 0; i < 26; i++) {
                  // 遞迴嘗試所有子節點
                  if (node->children[i] &&
                      search_helper(word, pos + 1, node->children[i]))
                      return true;
              }
              return false;
          } else {
              // 如果是字符，向下搜尋
              int idx = word[pos] - 'a';
              if (!node->children[idx]) {
                  return false;
              }
              return search_helper(word, pos + 1, node->children[idx]);
          }
      }
  
      // 解構函數（避免記憶體洩漏）
      // ~WordDictionary() {
      //     deleteTrie(root);
      // }
  
      // 遞迴刪除不必要的記憶體
      // void deleteTrie(TrieNode* node) {
      //     if (!node) return;
      //     for (int i = 0; i < 26; i++) {
      //         deleteTrie(node->children[i]);
      //     }
      //     delete node;
      // }
  };
  
  /**
   * Your WordDictionary object will be instantiated and called as such:
   * WordDictionary* obj = new WordDictionary();
   * obj->addWord(word);
   * bool param_2 = obj->search(word);
   */