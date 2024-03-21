class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //my answer will be from 1 to n
        int n=nums.size();

        for(int i=0;i<n;i++){
            //we are removing negative numbers and numbers >n as these will never be our answer
            if(nums[i]<=0 || nums[i]>n){ nums[i]=n+1; }
        }

        for(int i=0;i<n;i++){
            
            int ind=abs(nums[i])-1;

            if(ind>n-1){ continue; }

            if(nums[ind]>0){
            nums[ind]=-1*nums[ind];
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0){ return i+1; }
        }

        return n+1;
    }
};