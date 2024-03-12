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
    ListNode* removeZeroSumSublists(ListNode* head) {
      ListNode* curr=head;
      unordered_map<int,ListNode*>mp;
      int sum=0;

      while(curr !=NULL){
        sum+=curr->val;
        if(sum==0){
            head=curr->next;
            curr->next=NULL;
            curr=head;
            mp.clear();
        }
        else if(mp.find(sum) !=mp.end()){
            ListNode* temp=mp[sum];
            int prefixSum=sum;
            while(temp->next !=curr){
                temp=temp->next;
                prefixSum+=temp->val;
                mp.erase(prefixSum);
                }

            mp[sum]->next=curr->next;
            curr->next=NULL;
            curr=mp[sum]->next;
        }
        else{ mp[sum]=curr;
        curr=curr->next;
        }

      }
      return head;
    }
};