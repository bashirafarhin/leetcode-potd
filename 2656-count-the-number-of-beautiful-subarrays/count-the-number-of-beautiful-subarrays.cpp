class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
     int n=nums.size();
     vector<int> prefix(n,0);
     unordered_map<int,int> mp;
     prefix[0]=nums[0];
     for(int i=1;i<n;i++){prefix[i]=prefix[i-1]^nums[i];}
     long long ans=0;
     mp[0]=1;
     for(int i=0;i<n;i++){
         if(mp[prefix[i]]){ans+=mp[prefix[i]];}
         mp[prefix[i]]++;
     }
     return ans;
    }
};