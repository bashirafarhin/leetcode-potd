class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        int n=nums.size();
        int sum=0;
        vector<int>power;

        for(int i=1;i<k;i++){
            sum=(nums[i]==nums[i-1]+1) ? sum+1 : 0;
        }

        if(sum==k-1){
            power.push_back(nums[k-1]);
            sum--;
        } else {
            power.push_back(-1);
        }

        for(int i=k;i<n;i++){
            sum=(nums[i]==nums[i-1]+1) ? sum+1 : 0;
            if(sum==k-1){
                power.push_back(nums[i]);
                sum--;
            } else {
                power.push_back(-1);
            }
        }
        return power;
    }
};