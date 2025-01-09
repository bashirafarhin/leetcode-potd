class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
       int ans=0;
       for(string word : words){
        if(word.size()<pref.size()){ continue; }
        int j=0;
        for(;j<pref.size();j++){
            if(word[j] !=pref[j]){ break; }
        }
        if(j==pref.size()){ ans++; }
       }
       return ans;
    }
};