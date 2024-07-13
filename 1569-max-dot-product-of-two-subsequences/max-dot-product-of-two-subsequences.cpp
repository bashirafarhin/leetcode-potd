class Solution {
public:
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp){
        if(i==nums1.size() || j==nums2.size()){ return INT_MIN; }
        if(dp[i][j] !=INT_MIN){ return dp[i][j]; }
        int res=solve(i+1,j+1,nums1,nums2,dp);
        int a=nums1[i]*nums2[j];
        if(res !=INT_MIN){
            res+=a;
        }
        int b=solve(i+1,j,nums1,nums2,dp);
        int c=solve(i,j+1,nums1,nums2,dp);
        return dp[i][j]=max({a,b,c,res});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,INT_MIN));
        return solve(0,0,nums1,nums2,dp);
    }
};