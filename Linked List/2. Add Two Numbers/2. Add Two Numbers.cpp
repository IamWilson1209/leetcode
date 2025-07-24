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
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          ListNode* dummy = new ListNode(0);
          ListNode* temp = dummy;
          int bonus = 0;
  
          while (l1 || l2 || bonus) {
              int value1 = l1 ? l1->val : 0;
              int value2 = l2 ? l2->val : 0;
              int sum = value1 + value2 + bonus;
              
              bonus = sum / 10;
              int value = sum % 10;
  
              temp->next = new ListNode(value);
              temp = temp->next;
  
              l1 = l1 ? l1->next : nullptr;
              l2 = l2 ? l2->next : nullptr;
          }
  
          return dummy->next;
      }
  };
  