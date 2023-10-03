class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
     map<int,int> map;
     int ans=0;
     int n=nums.size();
     for(int i=0;i<n;i++){
         if(map.find(nums[i]) !=map.end()){
             ans+=map[nums[i]];
             map[nums[i]]++;
         }
         else{map[nums[i]]=1;}
     }
     return ans;
    }
};