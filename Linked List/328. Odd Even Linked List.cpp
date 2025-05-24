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
      ListNode* oddEvenList(ListNode* head) {
          if (!head || !head->next) return head;
  
          ListNode* oddHead = new ListNode(0);
          ListNode* oddTemp = oddHead;
          ListNode* evenHead = new ListNode(0);
          ListNode* evenTemp = evenHead;
          ListNode* cur = head;
          bool isOdd = true;
  
          while (cur) {
              if (isOdd) {
                  oddTemp->next = cur;
                  oddTemp = oddTemp->next;
              } else {
                  evenTemp->next = cur;
                  evenTemp = evenTemp->next;
              }
              cur = cur->next;
              isOdd = !isOdd;
          }
  
          oddTemp->next = evenHead->next;
          evenTemp->next = nullptr; /* 確保偶數鏈表尾部為空 */
          ListNode* result = oddHead->next;
  
          return result;
      }
  };