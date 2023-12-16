class Trienode{
 public:
 Trienode* children[2];
 Trienode(){
    this->children[0]=NULL;
    this->children[1]=NULL;
 }
};
class Trie{
    public:
    Trienode* root;
    Trie(){
    this->root=new Trienode();}
    void insert(int num){
        Trienode* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num >> i) & 1;
            if(curr->children[bit]==NULL){
                curr->children[bit]=new Trienode();
            }
            curr=curr->children[bit];
        }}
    int getmax(int num){
        Trienode* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(num >> i) & 1;
            if(curr->children[1-bit] !=NULL){
             curr=curr->children[1-bit];
             ans = ans | (1<<i);
            } else {
             curr=curr->children[bit];}
            
        }
        return ans;}
};

class Solution {

public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int n=nums.size();
        for(int i=0;i<n;i++){trie.insert(nums[i]);}
        int ans=0;
        for(int i=0;i<n;i++){ans=max(ans,trie.getmax(nums[i]));}
        return ans;
    }
};