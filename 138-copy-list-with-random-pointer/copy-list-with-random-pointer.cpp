/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>omap;
        unordered_map<Node*,Node*>nmap;

        Node* nhead=NULL;
        Node* ncurr=NULL;
        Node* curr=head; 
        
        while(curr !=NULL){
         
          Node* node=new Node(curr->val);
          if(nhead==NULL){
              nhead=node;
              ncurr=nhead;
          }
          else{
              ncurr->next=node;
              ncurr=ncurr->next;
          }
         omap[curr]=ncurr;
         nmap[ncurr]=curr;
         curr=curr->next;
        }
        //copy random pointer
        ncurr=nhead;
        while(ncurr !=NULL){
         Node* x=omap[nmap[ncurr]->random];
         ncurr->random=x;
         ncurr=ncurr->next;
        }
        return nhead;
    }
};