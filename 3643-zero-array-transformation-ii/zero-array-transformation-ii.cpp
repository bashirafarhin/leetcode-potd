class Solution {
public:
    bool countMinQueries(vector<int>& nums, vector<vector<int>>& queries, int k){
        int n=nums.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            prefix[l]+=val;
            prefix[r+1]-=val;
        }
        for(int i=1;i<n;i++){
            prefix[i]+=prefix[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>prefix[i]){ return 0; }
        }
        return 1;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=INT_MAX;
        int l=0;
        int h=queries.size();
        while(l<=h){
            int m=l+(h-l)/2;
            if(countMinQueries(nums,queries,m)){
                ans=min(ans,m);
                h=m-1;
            } else {
                l=m+1;
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};