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
      ListNode* reverseList(ListNode* head) {
          /* Conditions head == null || no null */
          if (head == nullptr) return nullptr;
          /* 
              Three pointer: 
              temp: 暫存下一個ListNode 
              head: 處理到哪個ListNode
              ans: 儲存Reverse Linked List
          */
          ListNode *ans = nullptr;
          while (head != nullptr) {
              /* temp 暫存下一個ListNode(還沒被反轉) */
              ListNode* temp = head->next;
              /* 反轉：head 接給空的ans(或前一個ListNode)，ans回去head*/
              head->next = ans;
              ans = head;
              /* head處裡完，往下一個點移動 */
              head = temp;
          }
          return ans;
  
      }
  };