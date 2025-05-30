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
      ListNode* sortList(ListNode* head) {
          if (!head || !head->next) return head;
  
          ListNode* slow = head;
          ListNode* fast = head->next; /* 初始化 fast = head->next 讓 fast 比 slow 提前一步 */
          while (fast && fast->next) {
              slow = slow->next;
              fast = fast->next->next;
          }
  
          ListNode* mid = slow->next;
          slow->next = nullptr;
  
          ListNode* left = sortList(head);
          ListNode* right = sortList(mid);
  
          return merge(left, right); /* 將兩個已排序的子鏈表合併為一個排序的鏈表 */
      }
  
      /*
      merge(4, 2)：
          比較：2 < 4，選 2，結果：2->...
          剩餘 4，連接到尾部：2->4
      */
      ListNode* merge(ListNode* l1, ListNode* l2) {
          ListNode dummy(0);
          ListNode* tail = &dummy; /* 初始指向當前合併結果的"尾部" */
  
          while (l1 && l2) {
              if (l1->val < l2->val) {
                  tail->next = l1; /* 選擇較小的節點連接到 tail->next */
                  l1 = l1->next;
              } else {
                  tail->next = l2;
                  l2 = l2->next;
              }
              tail = tail->next;
          }
  
          tail->next = l1 ? l1 : l2;
          return dummy.next;
      }
  };