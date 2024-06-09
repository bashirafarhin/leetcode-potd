class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0){ return 0; }
        int i=0,j=0,n=nums.size(),ans=0;
        long long int K=k;
        long long int prod=1;
        for(int i=0;i<n;i++){
            prod*=(long long int)nums[i];
            while(j<=i && prod>=K){
                prod=prod/nums[j];
                j++;
            }
            if(j<=i) ans+=(i-j+1);
        }
        return ans;
    }
};