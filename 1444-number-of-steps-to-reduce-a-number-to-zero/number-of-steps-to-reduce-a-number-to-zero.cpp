class Solution {
public:
    int numberOfSteps(int num) {
        int steps=0;
        while(num){
            steps++;
            if(num%2==0){num>>=1;}
            else{num--;}
        }
        return steps;
    }
};