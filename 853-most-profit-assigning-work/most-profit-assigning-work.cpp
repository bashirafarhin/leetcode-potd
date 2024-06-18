class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({difficulty[i], profit[i]});
        }
        sort(arr.begin(), arr.end());
        sort(worker.begin(), worker.end());
        int ans = 0;
        priority_queue<int> pq;
        int m = worker.size();
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j < n && worker[i] >= arr[j].first) {
                pq.push(arr[j].second);
                j++;
            }
            if (!pq.empty()) {
                ans += pq.top();
            }
        }
        return ans;
    }
};