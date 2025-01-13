class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        for(char ch : s){
            freq[ch-'a']++;
        }
        int ans=0;
        for(int n : freq){
            if(n) ans+=(n & 1 ? 1 : 2);
        }
        return ans;
    }
};