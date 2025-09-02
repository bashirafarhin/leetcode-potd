class Solution {
public:

    int expand(int left, int right, string&s ){
        int n=s.size();
        int len=1;
        while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
                len+=2;
        }
        return len;
    }

    string longestPalindrome(string s) {
        int maxLength=0;
        int start=0;
        int n=s.size();
        for(int i=0; i<n;i++){

            int left=i-1;
            int right=i+1;
            int len=1;
            while(left>=0 && right<n && s[left]==s[right]){ left--; right++; len+=2; }

            if(len>maxLength){ maxLength=len; start=left+1; }

            left=i;
            right=i+1;
            len=0;
            while(left>=0 && right<n && s[left]==s[right]){ left--; right++; len+=2; }

            if(len>maxLength){ maxLength=len; start=left+1; }

        }
        return s.substr(start, maxLength);
    }
};