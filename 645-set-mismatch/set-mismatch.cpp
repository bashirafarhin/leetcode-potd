class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int repeat=0;
        int missing=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ind=abs(nums[i])-1;
            if(nums[ind]<0){
                repeat=abs(nums[i]);}
            else{
                nums[ind]=nums[ind]*-1;
            }
        }

        for(int i=0;i<n;i++){
         if(nums[i]>0){
             missing=i+1;
             break;}
        }

        return {repeat,missing};

    }
};