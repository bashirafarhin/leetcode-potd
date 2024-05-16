class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        int operations=0;
        int changes=0;
        vector<int>freqs(26,0),freqt(26,0);
        for(int i=0;i<n;i++){
            freqs[s[i]-'a']++;
            freqt[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freqt[i]>freqs[i]){ operations+=( freqt[i]-freqs[i] ); } 
        }
        return operations;
    }
};