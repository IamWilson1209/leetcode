# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        bonus = 0
        dummy = ListNode(0)
        temp = dummy

        while l1 or l2 or bonus:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            sum_val = val1 + val2 + bonus

            bonus = sum_val // 10
            val = sum_val % 10

            temp.next = ListNode(val)
            temp = temp.next

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        
        return dummy.next