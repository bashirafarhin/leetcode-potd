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
        unordered_map<Node*,Node*>map;

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
         map[curr]=ncurr;
         curr=curr->next;
        }
        //copy random pointer
        curr=head;
        ncurr=nhead;
        while(ncurr !=NULL){
         ncurr->random=curr->random? map[curr->random]: NULL;
         ncurr=ncurr->next;
         curr=curr->next;
        }
        return nhead;
    }
};