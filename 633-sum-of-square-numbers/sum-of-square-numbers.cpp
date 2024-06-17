class Solution {
public:
    bool judgeSquareSum(int c) {
     int l=0;
     long long int h=pow(c,0.5);
     while(l<=h){
        long long int target=l*l+h*h;
        if(target==c){ return true; }
        else if(target>c){ h--; }
        else{ l++; }
     }
     return false;
    }
};