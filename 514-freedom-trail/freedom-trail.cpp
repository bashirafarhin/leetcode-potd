class Solution {
public:
// TC m^n
// with dp m*n*n
    int helper(int ringIndex,int keyIndex,string ring, string key,vector<vector<int>>&dp){
        if(keyIndex==key.size()){
            return 0;
        }
        if(dp[ringIndex][keyIndex] !=-1){
            return dp[ringIndex][keyIndex];
        }
        int n=ring.size();
        int res=INT_MAX;
        for(int i=0;i<n;i++){
           if(ring[i]==key[keyIndex]){
            int anti=abs(i-ringIndex);
            int clockwise=ring.size()-anti;
            int steps=1+min(anti,clockwise);
            int totalSteps=steps+helper(i,keyIndex+1,ring,key,dp);
            res=min(res,totalSteps);
           }
        }
        return dp[ringIndex][keyIndex]=res;
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.size();
        int m=key.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,ring,key,dp);
    }
};