class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int i=0;
        for(;i<n;i++){
            if(s[i]=='0'){ i++; break; }
        }

        for(;i<n;i++){
            if(s[i]=='1'){ return false; }
        }

        return true;
    }
};