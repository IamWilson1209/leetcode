// TrieNode節點類
class TrieNode {
  public:
      bool is_word;
      TrieNode* children[26];

      TrieNode() {
          is_word = false;
          for (int i = 0; i < 26; i++) {
              children[i] = nullptr;
          }
      }
};
// Trie樹類
class Trie {
  private:
      TrieNode* root;
  public:
      Trie() {
          root = new TrieNode();
      }

      void insert(string word) {
          TrieNode* node = root;
          for (char c : word) {
              int idx = c - 'a';
              if (!node->children[idx]) {
                  node->children[idx] = new TrieNode();
              }
              node = node->children[idx];
          }
          node->is_word = true;
      }
  // 添加公共方法來訪問 root
      TrieNode* getRoot() {
          return root;
      }
};

class Solution {
private:
  int rows, cols;
  vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  vector<string> ans;
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      rows = board.size();
      cols = board[0].size();

      // 初始化trie
      Trie* trie = new Trie();
      for (string& word : words) {
          trie->insert(word);
      }

      // 從每個格子開始dfs
      string word;
      for (int row = 0; row < rows; row++) {
          for (int col = 0; col < cols; col++) {
              dfs(board, row, col, trie->getRoot(), word);
          }
      } 

      delete trie;      

      return ans;
  }
private:
  void dfs (vector<vector<char>>& board, int row, int col, TrieNode* node, string& word) {
      if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] == '#') {
          return;
      }

      char c = board[row][col]; // 暫存，回溯會用到
      int idx = c - 'a';
      if (!node->children[idx]) return; // 如果 Trie 中沒有這個字符，停止

      // 有這個字符，繼續移動到下一個Trie節點
      node = node->children[idx];
      word.push_back(c);

      // 如果下一個字找到完整單詞，加入答案
      if (node->is_word) {
          ans.push_back(word);
          node->is_word = false; // 取消is-word，避免重複添加同一單詞
      }

      // 沒找完，先標記已訪問
      board[row][col] = '#';

      // 繼續找
      for (auto& dir : dirs) {
          int nextRow = row + dir[0];
          int nextCol = col + dir[1];
          dfs(board, nextRow, nextCol, node, word);
      }

      // 恢復格子狀態並回溯
      board[row][col] = c;
      word.pop_back();
  }
};