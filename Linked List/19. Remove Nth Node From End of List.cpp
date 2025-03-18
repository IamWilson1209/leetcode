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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            // 好像沒有什麼高大尚的解法
            // 算多長
            int length = 0;
            ListNode* temp = head;
            while (temp) {
                temp =  temp->next;
                length++;
            }
            // 如果要刪的是頭節點
            if (length == n) {
                ListNode* newHead = head->next;
                delete head;
                return newHead;
            }
    
            // 找到要刪除的前一個節點
            ListNode* prev = head;
            for (int i = 0; i < length - n - 1; i++) {
                prev = prev->next;
            }
    
            // 刪除掉
            temp = prev->next;
            prev->next = temp->next;
            delete temp;
            
            return head;
        }
    };