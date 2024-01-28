class Solution {
public:
    int countKeyChanges(string s) {
        int ans=0;
        int n=s.length();
        for(int i=1;i<n;i++){
            if( s[i] !=toupper(s[i-1]) && s[i] !=tolower(s[i-1])){ ans++;}            
        }
        return ans;
    }
};