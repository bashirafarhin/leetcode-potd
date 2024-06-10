class trieNode{
    public:
    trieNode* children[2];
    trieNode(){
        this->children[0]=NULL;
        this->children[1]=NULL;
    }
};

class Trie{
    public:
    trieNode* root;
    Trie(){
        this->root=new trieNode();
    }

    void insertHelper(trieNode* curr,int n,int i){
        if(i==-1){ return; }
        int bit= (n>>i) & 1;
        if(curr->children[bit]==NULL){ curr->children[bit]=new trieNode(); }
        insertHelper(curr->children[bit],n,i-1);
    }

    void insert(int n){
        insertHelper(root,n,31);
    }

    int getMaxHelper(trieNode* curr,int n,int i){
        if(i==-1){ return 0; }
        int bit=(n>>i) & 1;
        if(curr->children[1-bit]==NULL){
            return getMaxHelper(curr->children[bit],n,i-1);; }
        return (1<<i) + getMaxHelper(curr->children[1-bit],n,i-1);  
    }

    int getMax(int n){
        return getMaxHelper(root,n,31);
    }


};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie t;
        for(int i=0;i<n;i++){ t.insert(nums[i]); }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,t.getMax(nums[i]));
        }
        return ans;
    }
};