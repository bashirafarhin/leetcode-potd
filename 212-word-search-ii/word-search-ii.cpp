struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    string word;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        word="";
    }
};

class Trie {
public:
    TrieNode* getNode() { return new TrieNode(); }

    void insert(TrieNode* root, const string& key) {
        TrieNode* curr = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = getNode();
            }
            curr = curr->children[index];
        }
        curr->word=key;
        curr->isEndOfWord = true;
    }
};

class Solution {
public:
    vector<vector<int>>dxy={{-1,0},{0,1},{1,0},{0,-1}};
    vector<string>ans;
    void dfs(int r, int c, TrieNode* curr, vector<vector<char>>& board){
        if(r<0 || c<0 || r==board.size() || c==board[0].size() || board[r][c]=='#'){
            return;
        }
        char ch=board[r][c];
        if(!curr->children[ch-'a']){
            return;
        }
        curr=curr->children[ch-'a'];
        if(curr->isEndOfWord){
            ans.push_back(curr->word);
            curr->isEndOfWord=false; //to avoid duplicates in answer
        }
        board[r][c]='#';
        for(int i=0;i<4;i++){
            int newX=r+dxy[i][0];
            int newY=c+dxy[i][1];
            dfs(newX, newY, curr, board);
        }
        board[r][c]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        TrieNode* root = trie.getNode();
        for(string&s : words){
            trie.insert(root,s);
        }
        int r = board.size();
        int c = board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                dfs(i,j,root,board);
            }
        }
        return ans;
    }
};