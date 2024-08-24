class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        //solve this 0,6   1,7   2,8   3,11 , ans is 2
        vector<int>maxRightRange(n+1,0);
        for(int i=0;i<=n;i++){
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            maxRightRange[left]=max(maxRightRange[left],right);
        }

        int taps=0;
        int maxEnd=0;
        int currEnd=0;
        for(int i=0;i<=n;i++){
            if(i>maxEnd){
                return -1;
            }
            if(i>currEnd){
                taps++;
                currEnd=maxEnd;
            }
            maxEnd=max(maxEnd,maxRightRange[i]);
        }
        return taps;
    }
};