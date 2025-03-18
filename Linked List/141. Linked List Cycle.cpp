/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
      bool hasCycle(ListNode *head) {
          /*Initial condition*/
          if (head == nullptr || head->next == nullptr) return false;
  
          /*declare fast, slow index*/
          ListNode *fast = head;
          ListNode *slow = head;
          
          /*while loop: fast->next is not nullptr*/
          while (fast != nullptr && fast->next != nullptr) {
              fast = fast->next->next;
              slow = slow->next;
              /*if yes, return true*/
              if (fast == slow) {
                  return true;
              }
          }
  
          /*else return false*/
          return false;
      }
  };