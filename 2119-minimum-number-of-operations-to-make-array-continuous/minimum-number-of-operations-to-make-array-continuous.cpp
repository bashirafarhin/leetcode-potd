class Solution {
public:
    int minOperations(vector<int>& nums) {
       const int n = (int) nums.size();
        auto ar = nums;
        sort(ar.begin(), ar.end());
        ar.erase(unique(ar.begin(), ar.end()), ar.end());

        const int sz = (int) ar.size();
        int ans = n;
        for (int i = 0; i < sz; i++) {
            int l = ar[i];
            int r = l + n;
            int elem = lower_bound(ar.begin(), ar.end(), r) - (ar.begin() + i);
            ans = min(ans, n - elem);
        }

        return ans;  
    }
};