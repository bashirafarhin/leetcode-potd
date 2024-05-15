class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xDiff=abs(sx-fx);
        int yDiff=abs(sy-fy);
        if(xDiff==0 && yDiff==0 && t==1){ return false; }
        return min(xDiff,yDiff)+abs(xDiff-yDiff) <=t;
    }
};