class Solution {
public:
    bool isVowel(char& ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {
        int ans=0;
        int cnt=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){ cnt++; }
        }
        ans=cnt;
        for(int i=k;i<s.length();i++){
            if(isVowel(s[i])){ cnt++; }
            if(isVowel(s[i-k])){ cnt--; }
            ans=max(ans,cnt);
        }
        return ans;
    }
};