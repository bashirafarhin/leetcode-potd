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
      ListNode* prev=NULL;
      ListNode* curr=head;
      unordered_map<int,ListNode*>mp;
      int sum=0;
      vector<int>arr;

      while(curr !=NULL){
        sum+=curr->val;
        if(sum==0){
            head=curr->next;
            curr->next=NULL;
            prev=NULL;
            curr=head;
            mp.clear();
        }
        else if(mp.find(sum) !=mp.end()){
            while(arr.back() !=sum){
                mp.erase(arr.back());
                arr.pop_back(); }
            mp[sum]->next=curr->next;
            curr->next=NULL;
            prev=mp[sum];
            curr=prev->next;
        }
        else{ mp[sum]=curr;
        arr.push_back(sum);
        prev=curr;
        curr=curr->next;
        }

      }
      return head;
    }
};