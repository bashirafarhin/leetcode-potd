class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k = 3;
        int maxMajority = k - 1;
        int n = nums.size();
        vector<int> me(maxMajority, INT_MAX);
        vector<int> mec(maxMajority, 0);

        for (int i = 0; i < n; i++) {
            bool flag = true;
            int ind = -1;

            for (int j = 0; j < maxMajority; j++) {
                if (nums[i] == me[j]) {
                    flag = false;
                    mec[j]++;
                    break;
                }
                if (mec[j] == 0 && ind == -1) {
                    ind = j;
                }
            }

            if (flag) {
                if (ind != -1) {
                    me[ind] = nums[i];
                    mec[ind] = 1;
                } else {
                    for (int j = 0; j < maxMajority; j++) {
                        mec[j]--;
                        if (mec[j] == 0)
                            mec[j] = NULL;
                    }
                }
            }
        }

        fill(mec.begin(), mec.end(), 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < maxMajority; j++) {
                if (nums[i] == me[j]) {
                    mec[j]++;
                }
            }
        }

        for (int j = 0; j < maxMajority; j++) {
            if (mec[j] > n / k) {
                ans.push_back(me[j]);
            }
        }

        return ans;
    }
};