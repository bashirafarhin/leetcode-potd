class Solution {
    bool backtrack(vector<int>&arr,vector<int>&check,int i,int target,int k,int OGtarget){
        if(k==0){return true;}
        if(target==0){return backtrack(arr,check,0,OGtarget,k-1,OGtarget);}
        if(i==arr.size()){return false;}
        bool take=false;
       if (! (check[i] || arr[i] > target || (i > 0 and arr[i] == arr[i-1] && !check[i-1]) ) ){
    
         check[i]=1;
         take=backtrack(arr,check,i+1,target-arr[i],k,OGtarget);
         if(take==true){return true;}
         check[i]=0;
        } 
        bool nottake=backtrack(arr,check,i+1,target,k,OGtarget);
        return nottake;
        }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum=accumulate(nums.begin(),nums.end(),0);
    if(sum%k !=0 || nums.size()<k){return false;}
    sort(nums.begin(),nums.end(),greater<int>());
    vector<int> check(nums.size(),0);
    int subsetsum=sum/k;
    return backtrack(nums,check,0,subsetsum,k,subsetsum);
    }  
    
};