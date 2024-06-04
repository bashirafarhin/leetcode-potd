class Solution {
public:
    int longestPalindrome(string s) {
      int n=s.length();
      vector<int>freq(256,0);
      for(int i=0;i<n;i++){
        freq[s[i]]++;
      }
      int ans=0;
      int odd=0;
      for(int i=0;i<256;i++){
        if(freq[i]>0){    
            if(freq[i] & 1){
                ans+=(freq[i]-1);
                odd=1;
            }
            else{
                ans+=freq[i];
            }
        }
      }
      return ans+odd;
    }
};