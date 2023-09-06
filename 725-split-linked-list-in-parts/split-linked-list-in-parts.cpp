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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
     int len=0;
     ListNode* curr=head;
     while(curr){
         len++;
         curr=curr->next;}

     int eachpartsize=len/k;
     int extranodes=len%k;
     vector<ListNode*> ans;

     curr=head;
     ListNode* prev=NULL;
     while(head){
       int eachpartlen=eachpartsize;
       ans.push_back(curr);
       while(eachpartlen--){
           prev=curr;
           curr=curr->next;
       }
       if(extranodes !=0 && curr !=NULL){
           extranodes--;
           prev=curr;
           curr=curr->next;
       }
       if(prev!=NULL){
           head=curr;
           prev->next=NULL;
       }
     }
     while(ans.size() !=k){ans.push_back(NULL);}
     return ans;
    }
};