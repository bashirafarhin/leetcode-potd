class TrieNode {
    public:
    vector<TrieNode*>children;
    bool isEndOfWord;
    TrieNode() {
        this->children=vector<TrieNode*>(26,NULL);
        this->isEndOfWord=false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        for(char ch : word){
            if(curr->children[ch-'a']==NULL){
                curr->children[ch-'a']=new TrieNode();
            }
            curr=curr->children[ch-'a'];
        }
        curr->isEndOfWord=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char ch : word){
            if(curr->children[ch-'a']==NULL){
                return false;
            }
            curr=curr->children[ch-'a'];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(char ch : prefix){
            if(curr->children[ch-'a']==NULL){
                return false;
            }
            curr=curr->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */