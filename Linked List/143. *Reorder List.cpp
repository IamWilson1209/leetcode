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
        void reorderList(ListNode* head) {
            if (!head || !head->next) return; // 如果鏈表為空或只有一個節點，直接返回
    
            // 步驟 1：找到中點
            ListNode *half = head, *fast = head, *prev = nullptr;
            while (fast && fast->next) {
                prev = half; // prev指向half的前一個節點
                half = half->next;
                fast = fast->next->next;
            }
            // 分割前後兩半，prev 指向前半最後一個節點
            prev->next = nullptr; // 斷開前半部分
            ListNode* firstHalf = head; // 前半部分頭部
            ListNode* secondHalf = half; // 後半部分頭部
    
            // 步驟 2：反轉後半部分
            prev = nullptr;
            while (secondHalf) {
                ListNode* temp = secondHalf->next;
                secondHalf->next = prev;
                prev = secondHalf;
                secondHalf = temp;
            }
            secondHalf = prev; // 反轉後的後半部分頭部
    
            // 步驟 3：合併前後兩半
            while (firstHalf && secondHalf) {
                ListNode* temp1 = firstHalf->next; // 儲存前半的下一個節點
                ListNode* temp2 = secondHalf->next; // 儲存後半的下一個節點
                
                firstHalf->next = secondHalf; // 前半連接到後半
                if (temp1) secondHalf->next = temp1; // 後半連接到前半的下一個
                
                firstHalf = temp1; // 移動到前半的下一個
                secondHalf = temp2; // 移動到後半的下一個
            }
        }
    };