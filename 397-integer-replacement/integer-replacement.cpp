class Solution {
public:
    unsigned long long integerReplacement(unsigned long long n) {
       if(n==1){return 0;}
       if(n & 1)//odd
        {return 1+min(integerReplacement(n-1),integerReplacement(n+1));}
       return 1+integerReplacement(n/2);//even
    }
};