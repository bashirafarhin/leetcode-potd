class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        int n=nums.size();
        vector<int>arr;
        for(int i=0;i<k-1;i++){
            if(arr.empty() || nums[i-1]==nums[i]-1){
                arr.push_back(nums[i]);
            } else if(nums[i-1] !=nums[i]-1){
                arr={};
                arr.push_back(nums[i]);
            }
        }

        vector<int>ans;
        for(int i=k-1;i<n;i++){
            if(arr.empty() || nums[i-1]==nums[i]-1){
                arr.push_back(nums[i]);
                if(arr.size()==k){
                    ans.push_back(nums[i]);
                    arr.erase(arr.begin());
                } else {
                    ans.push_back(-1);
                }
            } else if(nums[i-1] !=nums[i]-1){
                arr={};
                ans.push_back(-1);
                arr.push_back(nums[i]);
            }
        }
        return ans;
    }
};