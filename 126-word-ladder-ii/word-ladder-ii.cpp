class Solution {
    unordered_map<string,int>mp;
    vector<vector<string>>ans;
public:
    void dfs(string& word, vector<string>&seq, string& beginWord){
        if(word==beginWord){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=mp[word];
        int n=word.length();
        for(int i=0;i<n;i++){
                char og=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(mp.find(word) !=mp.end() && mp[word]+1==steps){
                        seq.push_back(word);
                        dfs(word,seq,beginWord);
                        seq.pop_back();
                    }
                }
                word[i]=og;
            }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        mp[beginWord]=1;
        st.erase(beginWord);
        int n=beginWord.length();
        while(!q.empty()){
            string word=q.front();
            if(word==endWord){ break; }
            int steps=mp[word];
            q.pop();
            for(int i=0;i<n;i++){
                char og=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word) !=st.end()){
                        q.push(word);
                        st.erase(word);
                        mp[word]=steps+1;
                    }
                }
                word[i]=og;
            }
        }
        if(mp.find(endWord) !=mp.end()){
            vector<string>sequence;
            sequence.push_back(endWord);
            dfs(endWord,sequence,beginWord);
        }
        return ans;
    }
};