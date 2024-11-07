class Solution {
public:
    bool divisorGame(int n) {
        return (n-1) & 1 ? true : false;
    }
};