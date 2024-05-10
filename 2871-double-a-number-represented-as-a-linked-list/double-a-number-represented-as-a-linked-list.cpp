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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){ return head; }
        ListNode* newHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }

    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);
        ListNode* curr=head;
        int carry=0;
        while(curr){
            int num=curr->val*2+carry;
            curr->val=num%10;
            carry=num/10;
            curr=curr->next;
        }
        head=reverse(head);
        if(carry){
            ListNode* newHead=new ListNode(carry);
            newHead->next=head;
            return newHead;
        }
        return head;
    }
};