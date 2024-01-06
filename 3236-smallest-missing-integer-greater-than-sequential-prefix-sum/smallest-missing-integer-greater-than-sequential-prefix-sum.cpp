class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                ans+=nums[i];}
            else {
                break;
            }
        }
       
        while(st.find(ans) !=st.end()){
            ans++;
        }
        return ans;
        
    }
};