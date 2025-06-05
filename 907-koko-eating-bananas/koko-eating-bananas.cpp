class Solution {
public:
    bool checkIfFinish(vector<int>& piles, int h, int k) {
        int timeRequired = 0;
        for (int i = 0; i < piles.size(); i++) {
            timeRequired += (piles[i] + k - 1) / k; // instead of ceil use this;
            if(timeRequired>h){ return false; }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // sum denotes the maximum time she requires to finish all off by eating
        // only 1 banana at one time
        int start = 1;
        int maxE = *max_element(piles.begin(), piles.end());
        int end = maxE;
        int ans = maxE;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (checkIfFinish(piles, h, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};