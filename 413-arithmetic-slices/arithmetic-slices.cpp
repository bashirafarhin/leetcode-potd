class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int cnt=0;
            while(i<n-2 && nums[i+1]-nums[i]==nums[i+2]-nums[i+1]){
                cnt++;
                ans+=cnt;
                i++;
            }
        }
        return ans;
    }
};