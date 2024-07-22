class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>currDiffCount;
        vector<int>oneOp(k+1,0);

        for(int i=0;i<n/2;i++){
            int diff=abs(nums[i]-nums[n-i-1]);
            currDiffCount[diff]++;
            int mini=min(nums[i],nums[n-i-1]);
            int maxi=max(nums[i],nums[n-i-1]);
            int maxAcheivableDiff=max(k-mini,maxi-0);
            oneOp[maxAcheivableDiff]++;
        }

        for(int maxAchievableDiff=k-1;maxAchievableDiff>=0;maxAchievableDiff--){
            oneOp[maxAchievableDiff]+=oneOp[maxAchievableDiff+1];
        }

        int ans=INT_MAX;
        for(auto [diff,count] : currDiffCount){
            int oneExtra= oneOp[diff]-count;
            int two=n/2-oneExtra-count;
            ans=min(ans,oneExtra+two*2);
        }

        return ans;
    }
};