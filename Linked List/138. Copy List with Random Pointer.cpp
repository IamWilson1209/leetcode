/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
      Node* copyRandomList(Node* head) {
          if (!head) return nullptr;
  
          // deep copy一定要先創建新節點，才能有指標
          // 因為random會亂跳，直接loop可能跳到還沒創建到的節點(next也是一樣)
          /*  1 -> 2 -> 3
              |    |    |
              v    v    v
              3    1   nullptr
          */
          unordered_map<Node*, Node*> old_to_new;
  
          Node* cur = head;
          // 使用 new Node(cur->val) 創建一個新節點
          // 僅複製 val，此時 next 和 random 仍為 nullptr
          while (cur) {
              old_to_new[cur] = new Node(cur->val);
              cur = cur->next;
          }
  
          cur = head;
          while (cur) {
              // 新的next = 舊的next(random同理)
              old_to_new[cur]->next = old_to_new[cur->next];
              old_to_new[cur]->random = old_to_new[cur->random];
              cur = cur->next;
          }
          return old_to_new[head];
      }
  };