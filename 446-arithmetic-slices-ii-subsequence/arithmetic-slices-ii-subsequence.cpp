class Solution {
public:
//brute force find all subsequence and check if they are arithmetic or not
//O(2^n)*n
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<unordered_map<long long,int>> dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff=(long long)nums[i]-(long long)nums[j];
                int cnt=(dp[j].find(diff)==dp[j].end() ? 0 : dp[j][diff]);
                ans+=cnt;
                dp[i][diff]+=(cnt+1);
            }
        }
        return ans;
    }
};