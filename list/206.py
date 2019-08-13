# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        pre = None
        while head != None:
            next = head.next
            head.next = pre
            pre = head
            head = next
        return pre
