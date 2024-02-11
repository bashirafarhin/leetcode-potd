class Solution {

     int strStr(string haystack, string needle) {
     int ls=haystack.length();
     int lp=needle.length();
     int count=0;
     if(lp>ls){return 0;}
     vector<int> lps(lp,0);
     //build lps array
     lps[0]=0;
     int i=1;
     int j=0;
     while(i<lp){
         if(needle[i] !=needle[j]){
             if(j !=0){j=lps[j-1];}
             else{lps[i]=0;
                  i++;}
         }
         else{lps[i]=j+1;
          i++;
          j++;}
     }
     //find pattern
     j=0;//pointer of pattern
     i=0;//pointer of string
     while(i<ls){
         if(haystack[i] !=needle[j]){
            if(j !=0){j=lps[j-1];}
            else{j=0;
                i++;}}
         else{i++;
            j++;
            if(j==lp){count++;}
            }
         }

    return count;
     }




public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size();
        string s="";
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){ s+='1'; }
            else if(nums[i]==nums[i+1]){ s+='0'; }
            else{ s+='2'; }
        }
        string patt="";
        for(int n : pattern){
            if(n==-1){n=2;}
            char c=n+'0';
            patt+=(c);
        }
        
        return strStr(s,patt);
    }
};