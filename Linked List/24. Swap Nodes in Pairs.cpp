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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        // 使用動態分配的 dummy 節點
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head; // cur 代替 head 進行遍歷
        
        while (cur && cur->next) {
            // 當前節點和下一個節點
            ListNode* first = cur;
            ListNode* second = cur->next;
            
            // 交換
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            // 更新指針
            prev = first;
            cur = first->next; // cur 前進到下一對節點
        }
        
        return dummy->next;
    }
};

