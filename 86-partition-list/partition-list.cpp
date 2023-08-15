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
    ListNode* partition(ListNode* head, int x) {
     ListNode node1(0), node2(0);
     ListNode *head1 = &node1, *head2 = &node2;
     while (head !=NULL ){
      if(head->val<x)
       {head1->next=head;
        head1=head1->next;}
      else{
        head2->next=head;
        head2=head2->next;}
      head=head->next;
        }
      head2->next=NULL;
      head1->next=node2.next;
      return node1.next;
    }
};