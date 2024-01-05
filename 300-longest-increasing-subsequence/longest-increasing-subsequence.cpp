class Solution {

public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1; prev>=-1 ;prev--){
                  int take=0;
                  if(prev==-1 || nums[prev]<nums[i]){
                   take=1+next[i+1];
                   }
                  int nottake=next[prev+1];
                  curr[prev+1]=max(take,nottake);  
                }
                next=curr;
            
        }
       return next[0];
    }
};