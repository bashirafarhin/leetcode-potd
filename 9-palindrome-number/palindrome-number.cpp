class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){ return false; }
        long reverse=0;
        int copy=x;
        while(copy>=10){
            int rem=copy%10;
            reverse=(reverse+rem)*10;
            copy=copy/10;
        }
        reverse+=copy;
        return reverse==x;
    }
};