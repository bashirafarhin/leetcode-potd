class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            while(i>0 && i<n && nums[i-1]==nums[i]){
                i++;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int s=nums[i]+nums[j]+nums[k];

                if(s==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while(j<n && nums[j-1]==nums[j]){ j++; }
                    
                } else if(s>0){
                    k--;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};