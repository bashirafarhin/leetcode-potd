class Solution {
    int solve(int start,int end,vector<int>& nums){
     int prev=0;
     int curr=nums[start];
     for(int i=start+1;i<end;i++){
         int nottake=curr;
         int take=nums[i];
         if (i>=2){
          take+=prev;}
         prev=curr;
         curr=max(take,nottake);
     }
     return curr;
    }

public:
    int rob(vector<int>& nums) {
      int n=nums.size();
      if(n==1){return nums[0];}
      return max(  solve(0,n-1,nums) , solve(1,n,nums) );
    }
};