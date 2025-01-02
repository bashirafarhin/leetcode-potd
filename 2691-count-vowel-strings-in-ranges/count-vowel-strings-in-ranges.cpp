class Solution {
public:
    int isVowel(char& ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int isStartAndEndWithVowel(string& word){
        return isVowel(word[0]) && isVowel(word[word.length()-1]);
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>prefix(n,0);
        prefix[0]=isStartAndEndWithVowel(words[0]);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+isStartAndEndWithVowel(words[i]);
        }
        vector<int>ans;
        for(auto q : queries){
            int l=q[0];
            int r=q[1];
            if(l==0){
                ans.push_back(prefix[r]);
            } else {
                ans.push_back(prefix[r]-prefix[l-1]);
            }
        }
        return ans;
    }
};