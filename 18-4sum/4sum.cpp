class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     int n=nums.size();
     vector<vector<int>>ans;
     sort(nums.begin(),nums.end());
     
     for(int i=0;i<n-3;i++){

        if(i>0 && nums[i-1]==nums[i]) continue;

         for(int j=i+1;j<n-2;j++){

            if(j>i+1 && nums[j-1]==nums[j]) continue;

             int p=j+1;
             int q=n-1;
             while(p<q){
                //long long sum=nums[i]+nums[j]+nums[p]+nums[q]
                //integer overflow error aajayega typecast hone se phle
                long long sum=nums[i]+nums[j];
                sum+=nums[p];
                sum+=nums[q];
                
                if(sum==target){
                    ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                    p++;
                    q--;
                    while(p<q && nums[p-1]==nums[p]){ p++; }
                    while(p<q && nums[q]==nums[q+1]){ q--; }
                }
                else if(sum>target){
                    q--;
                } else {
                    p++;
                }
             }
         }
     }
     return ans;  
    }
};