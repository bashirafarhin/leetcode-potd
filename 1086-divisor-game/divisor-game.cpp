class Solution {
public:
    bool divisorGame(int n) {
        //players can choose from 1---->n-1
      
        int turn = 1; //turn of alice to play
        while(n>1){
            n--;
            turn=1-turn;
        }
        if(turn==0){return true;}
        return false;
    }
};