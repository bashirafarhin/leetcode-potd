class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=i;j<n;j++){
                curr|=nums[j];
                if(curr>=k){
                    ans=min(ans,j-i+1);
                    break;
                }
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};