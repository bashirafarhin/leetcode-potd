class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int res=n;
        for(int i=0;i<26;i++){
            while(freq[i]>=3){
                res-=2;
                freq[i]-=2;
            }
        }
        return res;
    }
};