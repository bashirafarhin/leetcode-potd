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
        if(!head || !head->next) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            temp=curr;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1=reverse(l1);
        ListNode* rl2=reverse(l2);
        ListNode* ans=new ListNode(0);
        ListNode* head=ans;
        int carry=0;        
        while(rl1 && rl2){
            int sum=rl1->val+rl2->val+carry;
            carry=sum/10;
            head->next= new ListNode(sum % 10);
            head=head->next;
            rl1=rl1->next;
            rl2=rl2->next;
        }

        while(rl1){
            int sum=rl1->val+carry;
            carry=sum/10;
            head->next= new ListNode(sum % 10);
            head=head->next;
            rl1=rl1->next;
            }
        
        while(rl2){
            int sum=rl2->val+carry;
            carry=sum/10;
            head->next= new ListNode(sum % 10);
            head=head->next;
            rl2=rl2->next;
            }

        if(carry !=0){
            head->next=new ListNode(carry);
        }

        return reverse(ans->next);
    }
};