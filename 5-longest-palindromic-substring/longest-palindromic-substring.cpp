class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int len=0;
        int ans[2]={0,0};
        for(int i=0;i<n;i++){
            int start=i;
            int end=i;
            while(start>=0 && end<s.length() && s[start]==s[end]){
            start--;
            end++;
            }
            end--;
            start++;
            if(len<end-start+1){
                ans[0]=start;
                ans[1]=end;
                len=end-start+1;
            }
            start=i;
            end=i+1;
            while(start>=0 && end<s.length() && s[start]==s[end]){
            start--;
            end++;
            }
            start++;
            end--;
            if(len<end-start+1){
                ans[0]=start;
                ans[1]=end;
                len=end-start+1;
            }
        }
        return s.substr(ans[0],ans[1]-ans[0]+1);
    }
};