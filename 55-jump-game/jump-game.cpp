class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,true);
        for(int i=n-2;i>=0;i--){
            int range=nums[i];
            bool ans=false;
            for(int j=range;j>=1;j--){

             if(i+j>=n-1){
              ans=true;
              break;}

             else {
             ans=dp[i+j];
             if(ans==true){
              break;}}
            }
         dp[i]=ans;
        }
        return  dp[0];
    }
};