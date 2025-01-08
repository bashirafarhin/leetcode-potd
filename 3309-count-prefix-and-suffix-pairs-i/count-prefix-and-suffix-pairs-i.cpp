class Solution {
public:
    int isPrefixAndSuffix(string& word1, string& word2){
        if(word1.size()>word2.size()){ return 0; }
        for(int i=0;i<word1.size();i++){
            if(word1[i] !=word2[i]){ return 0; }
        }
        for(int i=word1.size()-1;i>=0;i--){
            if(word1[i] !=word2[word2.size()-word1.size()+i]){ return 0; }
        }
        return 1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
               ans+=isPrefixAndSuffix(words[i],words[j]); 
            }
        }
        return ans;
    }
};