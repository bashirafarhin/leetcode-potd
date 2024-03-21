# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reversell(self,head):
      if head is None or head.next is None:
        return head,head
      smallhead,smalltail=self.reversell(head.next)
      smalltail.next=head
      head.next=None
      smalltail=smalltail.next
      return smallhead,smalltail
     
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
      head,tail=self.reversell(head)
      return head