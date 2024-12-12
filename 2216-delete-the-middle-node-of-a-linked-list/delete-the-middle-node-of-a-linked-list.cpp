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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        if(fast->next !=NULL){
            prev=slow;
            slow=slow->next;
        }
        if(prev==NULL){
            ListNode* newHead=head->next;
            head->next=NULL;
            return newHead;
        }
        prev->next=slow->next;
        slow->next=NULL;
        return head;
    }
};