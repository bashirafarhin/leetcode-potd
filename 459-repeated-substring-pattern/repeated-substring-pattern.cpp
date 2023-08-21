class Solution {
public:
    
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
	    for(int i=n/2 ; i>=1 ; i--){
	        
	        if(n%i==0){ //substr lenght (i) should be multiple of s length
	             string pattern=s.substr(0,i);
	             int times=n/i;
	             string ns="";
	             while(times--){
	                 ns+=pattern;
	             }
	             if(ns==s){return true;}
	            
	            
	        }
	    }
	    return false;
    }
};