class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       //same as the question find the subarray having sum==k
       unordered_map<int,int>mp;
       int sum=0;
       int ans=0;
       int n=nums.size();
       mp[0]=1;
       for(int i=0;i<n;i++){
        sum+=nums[i];
        int rem=(sum % k + k)%k;
        if(i==0 || i==1){ cout<<rem<<endl; }
        if(rem==0 || mp.find(rem) !=mp.end()){
            ans+=mp[rem];
        }
        mp[rem]++;
       }
       return ans;
    }
};