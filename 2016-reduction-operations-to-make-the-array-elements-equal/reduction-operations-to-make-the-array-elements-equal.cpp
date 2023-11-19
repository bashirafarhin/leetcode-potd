class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int,greater<int>>mp;
        for(int &i:nums) mp[i]++;
        int ans=0;
        int ind=mp.size()-1;
        for(auto i:mp){ 
            int temp=i.second*ind; 
            ans+=(temp);
            ind--;
        }
        return ans;
    }
};