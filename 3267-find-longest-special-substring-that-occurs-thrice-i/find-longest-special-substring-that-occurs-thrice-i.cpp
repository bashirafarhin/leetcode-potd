class Solution {
public:
    int maximumLength(string s) {
        
        unordered_map<string,int> mp;
        for (int i = 0; i < s.length(); i++) {
        string subStr;
        for (int j = i; j < s.length(); j++) {
            subStr += s[j];
            if(j !=i && (s[i] !=s[j]) ){break;}
            mp[subStr]++;
       }}
        int ans=0;
        for(auto it : mp){
            if( (it.second>2) && (ans < it.first.length()) ){
                ans=it.first.length();}
        }
        if(ans==0){return -1;}
        return ans;
    }
};