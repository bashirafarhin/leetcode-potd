class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>diff;
        vector<int>changeOneNum(k+1,0);//max achievable difference by changing 1 number from a pair
        for(int i=0;i<n/2;i++){
            int d=abs(nums[i]-nums[n-i-1]);
            diff[d]++;
            int maxAchievableDiff=max(k-min(nums[i],nums[n-i-1]),max(nums[i],nums[n-i-1])-0);
            changeOneNum[maxAchievableDiff]++;
        }
        //propogating the changes
        for(int i=k-1;i>=0;i--){
            changeOneNum[i]+=changeOneNum[i+1];
        }
        int ans=n;
        for(auto it : diff){
            int d=it.first;
            int zeroChanges=it.second;
            int oneChanges=changeOneNum[d]-zeroChanges;
            int twoChanges=n/2-zeroChanges-oneChanges;
            ans=min(ans,oneChanges+twoChanges*2);
        }
        return ans;
    }
};