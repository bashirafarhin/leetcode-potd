class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>freq(26,0);
        for(char ch : s){
            freq[ch-'a']++;
        }
        int e=0,o=0;
        for(int n : freq){
            e+=(n/2);
            o+=(n%2);
        }
        if(o==k){ return true; }
        if(o>k){ return false; }
        if((o+2*e)>=k){ return true; }
        return false;
    }
};