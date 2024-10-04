class Solution {
public:
    // for each worker find max height it can reduce within the time limit
    long long MaxHeighReduceByWorkers(long long timeLimit, vector<int>& times, int mountainHeight) {
        int n = times.size();
        int totalHeightReduceByWorkers = 0; // within time limit
        for (int i = 0; i < n; i++) {
            int time = times[i];
            long long low = 0;
            long long high = 1e5;
            long long height = 0;
            while (low <= high) {
                long long mid = (low + high) / 2;
                // how much time required by worker i if needs to reduce height==mid
                long long timeRequired = mid * (mid + 1) / 2 * time;
                if (timeRequired <= timeLimit) {
                    low = mid + 1;
                    height = mid;
                } else {
                    high = mid - 1;
                }
            }
            totalHeightReduceByWorkers += height;
        }
        return totalHeightReduceByWorkers >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        long long high = 1e18;
        long long ans = high;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (MaxHeighReduceByWorkers(mid, workerTimes, mountainHeight)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};