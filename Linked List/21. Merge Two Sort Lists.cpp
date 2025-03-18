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
      ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
          /* 1. dummy ListNode*/
          ListNode *dummy = new ListNode(0);
          ListNode *ans = dummy;
          /* 2. while list1 && list2, compare which one bigger */
          while (list1 && list2) {
              if (list1->val <= list2->val) {
                  ans->next = list1;
                  list1 = list1->next;
              } else {
                  ans->next = list2;
                  list2 = list2->next;
              }
              /* ans go next */
              ans = ans->next;
          }
  
          /* 3. handle remain */
          ans->next = list1 ? list1 : list2;
  
          /* 4. return ListNode */

        //   ListNode* result = dummy->next;
        //   delete dummy;  // 釋放虛擬頭節點
        // return result;
          return dummy->next;
      }
  };