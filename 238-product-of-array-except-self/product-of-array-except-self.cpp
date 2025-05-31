class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        if(n==1){ return nums; }
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);

        for(int i=0;i<n;i++){
            prefix[i]=nums[i];
            if(i-1>=0){
                prefix[i]*=prefix[i-1];
            }

            int end=n-1-i;
            suffix[end]=nums[end];
            if(end+1<n){
                suffix[end]*=suffix[end+1];
            }
        }

        vector<int>ans(n,0);
        ans[0]=suffix[1];
        ans[n-1]=prefix[n-2];
        for(int i=1;i<n-1;i++){
            ans[i]=prefix[i-1]*suffix[i+1];
        }
        return ans;
    }
};