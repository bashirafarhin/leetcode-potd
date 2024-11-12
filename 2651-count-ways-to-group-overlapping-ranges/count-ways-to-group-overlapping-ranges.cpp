class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int mod=1e9+7;
        sort(ranges.begin(),ranges.end());
        int ans=1;
        int left=ranges[0][0];
        int right=ranges[0][1];
        for(int i=0;i<ranges.size();i++){
            if(i!=0 && right>=ranges[i][0]){
                left=min(left,ranges[i][0]);
                right=max(right,ranges[i][1]);
            } else {
                right=max(right,ranges[i][1]);
                ans=(ans%mod*2%mod)%mod;
            }
        }
        return ans; 
    }
};