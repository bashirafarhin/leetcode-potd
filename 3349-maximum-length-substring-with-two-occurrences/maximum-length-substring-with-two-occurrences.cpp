class Solution {
public:
    
    int maximumLengthSubstring(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        int ans=0;
        int start=0;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            while( freq[s[i]-'a']>2 ){
                freq[s[start]-'a']--;
                start++;
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};