class Solution {
public:
    int minOperations(vector<int>& nums) {
        //sorted and unique
        set<int>st(nums.begin(),nums.end());
        vector<int>temp(st.begin(),st.end());
        int n=nums.size();
        int ans=n;
        for(int i=0;i<temp.size();i++){
            int left=i;
            int right=temp[i]+n-1;
            int within_range=(upper_bound(temp.begin(),temp.end(),right)-temp.begin())-i;
            int out_of_range=n-within_range;
            ans=min(ans,out_of_range);
        }
        return ans;
    }
};