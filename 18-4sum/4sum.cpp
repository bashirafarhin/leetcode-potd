class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     int n=nums.size();
     vector<vector<int>>ans;
     sort(nums.begin(),nums.end());
     unordered_set<string> seen;
     
     for(int i=0;i<n-3;i++){

         for(int j=i+1;j<n-2;j++){

             int p=j+1;
             int q=n-1;
             while(p<q){
                //long long sum=nums[i]+nums[j]+nums[p]+nums[q]
                //integer overflow error aajayega typecast hone se phle
                long long sum=nums[i]+nums[j];
                sum+=nums[p];
                sum+=nums[q];
                
                if(sum==target){
                    
                    string x="";
                    x+=nums[i];
                    x+=nums[j];
                    x+=nums[p];
                    x+=nums[q];
                    if(seen.find(x)==seen.end()){
                        seen.insert(x);
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                    }
                    p++;
                    q--;
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