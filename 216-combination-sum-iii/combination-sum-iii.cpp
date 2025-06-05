class Solution {
public:
    void comb(int num, int k, int sum, vector<int>& curr, vector<vector<int>>& ans) {
        if (sum == 0 && k == 0) {
            ans.push_back(curr);
            return;
        }
        if (num > 9) {
            return;
        }
        if (sum - num >= 0 && k-1>=0) {
            curr.push_back(num);
            comb(num + 1, k - 1, sum - num, curr, ans);
            curr.pop_back();
            comb(num + 1, k, sum, curr, ans);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;
        comb(1, k, n, curr, ans);
        return ans;
    }
};