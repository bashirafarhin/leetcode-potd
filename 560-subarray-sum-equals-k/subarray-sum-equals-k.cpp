class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     //do dry run of 1 2 3 -3 1 1 1 4 2 -3
     int count=0;
     int n=nums.size();
     int prefixSum=0;
     unordered_map<int,int>mp; //prefixSum,itsCount
     mp[0]=1;
     for(int i=0;i<n;i++){
        prefixSum+=nums[i];
        if(mp.find(prefixSum-k) !=mp.end()){
            count+=mp[prefixSum-k];
        }
        mp[prefixSum]++;
     }
     return count;
    }
};