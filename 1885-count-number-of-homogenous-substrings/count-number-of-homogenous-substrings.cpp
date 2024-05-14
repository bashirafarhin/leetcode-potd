class Solution {
public:
    int mod=1e9+7;
    int countHomogenous(string s) {
       int ans=0;
       int j=0;
       for(int i=0;i<s.length();i++){
         if(s[j] !=s[i]){
            long long n=i-j;
            ans=(ans +(n%mod)*((n+1)%mod)/2)%mod;
            j=i;
         }
       }
       long long n=s.length()-j;
       ans=(ans +(n%mod)*((n+1)%mod)/2)%mod;
       return ans;
    }
};