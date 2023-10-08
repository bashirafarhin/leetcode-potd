class Solution {
public:
     vector<vector<int>> dp;
    int solve(vector<int> &nums1, vector<int> &nums2, int i , int j)
    {
        if(i == nums1.size() or j == nums2.size()) return 0;
        int a = INT_MIN;
        int b = INT_MIN;
        int c = INT_MIN;
        int d = INT_MIN;

        if(dp[i][j] != -1) return dp[i][j];

        a = solve(nums1,nums2,i+1,j+1) + nums1[i]*nums2[j];
        b = solve(nums1,nums2,i+1,j);
        c = solve(nums1,nums2,i,j+1);
        // d = solve(nums1,nums2,i+1,j+1);

        return dp[i][j] = max(a,max(b,c));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(nums2.size(),-1));
        int x = solve(nums1,nums2,0,0);
        if(x == 0)
        {
            int res = INT_MIN;
            for(int i = 0 ; i < nums1.size() ; i++)
            {
                for(int j = 0 ; j < nums2.size() ; j++)
                {
                    res = max(nums1[i]*nums2[j],res);
                }
            }
            return res;
        }
        return x;
    }
};