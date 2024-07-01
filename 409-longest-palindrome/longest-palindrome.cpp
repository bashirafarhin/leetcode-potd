class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(char c : s){ mp[c]++; }
        int even=0;
        int odd=0;
        int pairs=0;
        for(auto it : mp){
           pairs+=(it.second/2);
           if(it.second & 1){ odd=1; }
        }

        return odd ? pairs*2+1 : pairs*2 ;
    }
};