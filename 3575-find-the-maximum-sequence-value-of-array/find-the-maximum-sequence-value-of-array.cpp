class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> left(n, vector<vector<int>>(k + 1, vector<int>(129, 0)));
        vector<vector<vector<int>>> right(n, vector<vector<int>>(k + 1, vector<int>(129, 0)));
        left[0][1][nums[0]]=1;
        for (int i = 1; i < n; i++) {
            left[i][1][nums[i]]=1;
            for (int size = 1; size <= k; size++) { // subarray size
                for (int val = 0; val < 129; val++) {
                    if (left[i - 1][size][val]) {
                        left[i][size][val] = 1;
                    }
                    if (left[i-1][size - 1][val]) {
                        left[i][size][val | nums[i]] = 1;
                    }
                }
            }
        }
        right[n-1][1][nums[n-1]]=1;
        for (int i = n - 2; i >= 0; i--) {
            right[i][1][nums[i]]=1;
            for (int size = 1; size <= k; size++) { // subarray size
                right[i][1][nums[i]] = 1;
                for (int val = 0; val < 129; val++) {
                    if (right[i + 1][size][val]) {
                        right[i][size][val] = 1;
                    }
                    if (right[i+1][size - 1][val]) {
                        right[i][size][val | nums[i]] = 1;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n-1; i++) {
            for (int val1 = 0; val1 < 129; val1++) {
                if (left[i][k][val1]) {
                    for (int val2 = 0; val2 < 129; val2++) {
                        if (right[i+1][k][val2]) {
                            ans = max(ans, val1 ^ val2);
                        }
                    }
                }
            }
        }
        return ans;
    }
};