class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int cntg=0;
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                if(cnt==1){ return false; }
                if(s[i+1]=='0'){ cnt=1; }
                if(s[i+1]=='1'){ cntg+=1; }
            }
        }
        if(s[n-1]=='1' && cnt==1){ return false; }
        return true;
    }
};