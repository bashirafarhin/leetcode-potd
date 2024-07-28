class Solution {
public:
    void helper(int i,string s,unordered_set<string>st,vector<string>&curr,vector<string>&res){
        if(i==s.length()){
            string sentence="";
            for(auto word : curr){ sentence+=word+" ";}
            sentence.pop_back();
            res.push_back(sentence);
            return;
        }
        int n=s.length();
        string word="";
        for(int j=i;j<n;j++){
            word+=s[j];
            if(st.find(word) !=st.end()){
                curr.push_back(word);
                helper(j+1,s,st,curr,res);
                curr.pop_back();
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string word: wordDict){ st.insert(word); }
        vector<string>res;
        vector<string>curr;
        helper(0,s,st,curr,res);
        return res;
    }
};