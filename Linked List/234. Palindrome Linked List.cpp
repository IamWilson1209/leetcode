/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
      bool isPalindrome(ListNode* head) {
          if (!head || !head->next) return true; // 空或單節點是回文
  
          stack<ListNode*> visited;
          
          // 找到中點並將前半部分推入堆疊
          ListNode* half = head;
          ListNode* end = head;
          while (end && end->next) {
              visited.push(half); // 推入前半部分節點
              half = half->next;
              end = end->next->next;
          }
  
          if (end) half = half->next; // 奇數，偶數fast=nullptr
  
          // 比較前半部分（堆疊）和後半部分
          while (half) {
              if (visited.empty()) return false;
              int valueStart = visited.top()->val;
              int valueEnd = half->val;
              if (valueStart != valueEnd) return false;
              visited.pop();
              half = half->next;
          }
  
          // 確保堆疊正好清空
          return visited.empty();
  
      }
  };