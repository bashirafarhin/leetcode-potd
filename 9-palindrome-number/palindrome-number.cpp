class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){ return false; }
        string s = to_string(x);
        int n=s.size();
        int i=0;
        while(i<=n/2){
            if(s[i] != s[n-1-i]){ return false; }
            i++;
        }
        return true;
    }
};