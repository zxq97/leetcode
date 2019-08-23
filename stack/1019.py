# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        
        stack = []
        res = [0 for i in range(len(nums))]
        for i in range(len(nums)):
            while stack and nums[i] > nums[stack[-1]]:
                res[stack[-1]] = nums[i]
                stack.pop()
            else:
                stack.append(i)
        while stack:
            res[stack[-1]] = 0
            stack.pop()

        return res
