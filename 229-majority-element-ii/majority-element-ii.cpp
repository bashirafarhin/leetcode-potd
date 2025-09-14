class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k = 3;
        int maxMajority = k - 1;
        int n = nums.size();
        vector<int> candidates(maxMajority, INT_MAX);
        vector<int> counter(maxMajority, 0);

        for (int i = 0; i < n; i++) {
            bool found = true;
            int emptySlot = -1;

            for (int j = 0; j < maxMajority; j++) {
                if (nums[i] == candidates[j]) {
                    found = false;
                    counter[j]++;
                    break;
                }
                if (counter[j] == 0 && emptySlot == -1) {
                    emptySlot = j;
                }
            }

            if (found) {
                if (emptySlot != -1) {
                    candidates[emptySlot] = nums[i];
                    counter[emptySlot] = 1;
                } else {
                    for (int j = 0; j < maxMajority; j++) {
                        counter[j]--;
                        if (counter[j] == 0)
                            candidates[j] = INT_MAX;
                    }
                }
            }
        }

        fill(counter.begin(), counter.end(), 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < maxMajority; j++) {
                if (nums[i] == candidates[j]) {
                    counter[j]++;
                }
            }
        }

        for (int j = 0; j < maxMajority; j++) {
            if (counter[j] > n / k) {
                ans.push_back(candidates[j]);
            }
        }

        return ans;
    }
};