class Solution {
public:
     const int mod = 1e9 + 7;
    int countHomogenous(string s) {
        int i=0;
        int j=0;

        long long ans=0;

        while(j<s.length()){
            if(s[j]!=s[i]){
               long long n=j-i;
        
               ans=(ans + (n%mod*(n+1)%mod)/2)%mod;
               i=j;
            }
            j++;
        }
        long long n=j-i;
        ans=(ans + (n%mod*(n+1)%mod)/2)%mod;

        return ans;
    }
};