class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int ans=max(abs(sx-fx),abs(sy-fy));
        if(ans==0 && t==1) return 0;
        return ans<=t;
    }
};