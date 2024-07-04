class Solution {
public:
    void solve(vector<int>&nums,int i,int n,vector<vector<int>>&ans){
        if(i==n-1){
            ans.push_back(nums);
            return ;
        }
        unordered_set<int>st;
        for(int j=i;j<n;j++){
            if(st.find(nums[j]) !=st.end()){ continue; }

            st.insert(nums[j]);
            swap(nums[i],nums[j]);
            solve(nums,i+1,n,ans);
            swap(nums[i],nums[j]);
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        solve(nums,0,n,ans);
        return ans;
    }
};