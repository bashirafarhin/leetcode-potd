class Solution {
public:
    bool isSubstr(string str, string pattern){
        if(pattern.size()>str.size()){ return false; }
        int hashPat=0;
        for(char ch : pattern){
            hashPat+=(ch-'a');
        }
        int hashStr=0;
        for(int i=0;i<pattern.size()-1;i++){
            hashStr+=(str[i]-'a');
        }
        for(int i=pattern.size()-1;i<str.size();i++){
            hashStr+=(str[i]-'a');
            if(hashPat==hashStr){
                int j=0;
                for(;j<pattern.size();j++){
                    if(pattern[j] !=str[i-(pattern.size()-1)+j]){ break; }
                }
                if(j==pattern.size()){ return true; }
            }
            hashStr-=(str[i-(pattern.size()-1)]-'a');
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        for(string& word1 : words){
            for(string& word2 : words){
                if(word1 !=word2 && isSubstr(word2,word1)){
                    ans.push_back(word1);
                    break;
                }
            }
        }
        return ans;
    }
};