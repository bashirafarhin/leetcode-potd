class Solution {
public:
    string losingPlayer(int x, int y) {
        int level=y/4;
        if(level<=x){
            return (y % 8)>=4 ? "Alice" : "Bob";
        }
        return x & 1 ? "Alice" : "Bob";
    }
};