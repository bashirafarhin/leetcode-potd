class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int index=-1;
        int count=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
                if(count>1){ break; }
                index=i;
            } else {
                prod*=nums[i];
            }
        }
        vector<int>arr(n,0);
        if(count==1){
            arr[index]=prod;
        } else if(count==0){
            for(int i=0;i<n;i++){
                arr[i]=prod/nums[i];
            }
        }
        return arr;
    }
};