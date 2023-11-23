class Solution {
public:
    // Since the bounds are (n, m) <= (500, 500), we can simply sort numbers in each range and check if they uphold common difference.
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> result(m);
        for (int i = 0; i < m; i ++) {
            vector<int> temp(nums.begin() + l[i],
                             nums.begin() + r[i] + 1);
            sort(temp.begin(), temp.end());
            bool ap = true;
            int diff = temp[1] - temp[0];
            for (int i = 2; i < temp.size(); i ++) {
                if (temp[i] - temp[i - 1] != diff) {
                    ap = false;
                    break;
                }
            }
            result[i] = ap;
        }
        return result;
    }
};