class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
       int n=s.length();
       int i=0,start=0;
       int ans=0;
       while(i<n){
        maxCost-=abs(s[i]-t[i]);
        while(maxCost<0){
            maxCost+=abs(s[start]-t[start]);
            start++;
        }
        ans=max(ans,i-start+1);
        i++;
       }
       return ans;
    }
};