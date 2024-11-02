class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            sort(nums.begin(),nums.end());
            return ;
        }
        int nextGreater=-1;
        for(int i=n-1;i>=ind;i--){
            if(nums[i]>nums[ind]){
                nextGreater=i;
                break;
            }
        }
        swap(nums[ind],nums[nextGreater]);
        sort(nums.begin()+ind+1,nums.end());
        return ;
    }
};