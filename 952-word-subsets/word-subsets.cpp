class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>freq2(26,0);
        for(string& word : words2){
            vector<int>temp(26,0);
            for(char& ch : word){
                temp[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                freq2[i]=max(freq2[i],temp[i]);
            }
        }
        vector<string>ans;
        for(string& word : words1){
            vector<int>freq1(26,0);
            for(char& ch : word){
                freq1[ch-'a']++;
            }
            int i=0;
            for(;i<26;i++){
                if(freq1[i]<freq2[i]){ break; }
            }
            if(i==26){ ans.push_back(word); }
        }
        return ans;
    }
};