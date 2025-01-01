class Solution {
public:
    int maxScore(string s) {
        int cnt1=0;
        int cnt0=0;
        for(char ch : s){
            if(ch=='1'){ cnt1++; }
        }
        int ans=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0'){
                cnt0++;
            } else {
                cnt1--;
            }
            ans=max(ans,cnt0+cnt1);
        }
        return ans;
    }
};