class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //video -code with monk
        stack<int> st;
        int n=nums.size();
        int third=-1e9;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<third){ return true; }
            while(!st.empty() && nums[i]>st.top()){
                third=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};