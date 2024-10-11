class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        stack<pair<int, int>> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (st.empty() || i + nums[i] >= st.top().first) {
                while (!st.empty() && i + nums[i] >= st.top().second) {
                    st.pop();
                }
                if (st.empty()) {
                    st.push({i, n - 1});
                } else {
                    st.push({i, st.top().first});
                }
            }
        }
        return st.size();
    }
};