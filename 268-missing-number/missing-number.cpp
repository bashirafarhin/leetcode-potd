class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            nums[i]+=1;
        }

        for(int i=0;i<n;i++){
            int ind=abs(nums[i])-1;
            if(ind<n){
                nums[ind]=-1*nums[ind];
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i;
            }
        }

        return n;
    }
};