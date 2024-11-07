class Solution {
public:
    string losingPlayer(int x, int y) {
        int turn=1;
        while(true){
            if(x<1 || y<4){
                return !turn ? "Alice" : "Bob";
            }
            x--;
            y-=4;
            turn=1-turn;
        }
    }
};