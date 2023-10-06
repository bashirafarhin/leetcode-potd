class Solution {
public:
    int integerBreak(int n) {
       if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int num3 = n/3;
        int mod3 = n%3;
        int mult=3;
        if(mod3 == 0){
            for(int i=0; i< num3-1; i++){
                mult = mult*3; 
            }
        }
        else if(mod3 == 1){
            mult=4;
            for(int i=0; i< num3-1; i++){
                mult = mult*3; 
            }
        }
        else{
            mult=2;
            for(int i=0; i< num3; i++){
                mult = mult*3; 
            }
        }
        return mult;  
    }
};