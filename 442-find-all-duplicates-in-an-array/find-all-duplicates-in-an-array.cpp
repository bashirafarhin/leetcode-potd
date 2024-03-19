class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //brute force methods using sets and map
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int ind=abs(nums[i])-1;
            if(nums[ind]<0){
                ans.push_back(abs(nums[i]));
            } else {
                nums[ind]=-1*nums[ind];
            }
        }
        return ans;
    }
};