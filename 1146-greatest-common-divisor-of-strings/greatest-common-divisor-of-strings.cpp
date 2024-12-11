class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans="";
        int n=str1.length();
        int m=str2.length();
        if(n<m){ return gcdOfStrings(str2,str1); }
        for(int i=1;i<=m;i++){
            string check=str2.substr(0,i);
            int j=0;
            for(;j<n;j+=i){
                if(j<m && check != str2.substr(j,i)){ break; }
                if(check !=str1.substr(j,i)){ break; }
            }
            if(j==n){
                ans=check;
            }
        }
        return ans;
    }
};