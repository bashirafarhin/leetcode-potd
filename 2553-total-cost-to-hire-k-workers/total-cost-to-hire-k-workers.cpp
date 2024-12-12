class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;
        int start = 0;
        int end = costs.size() - 1;
        
        int cand=candidates;
        while (start<=end && cand) {
            left.push(costs[start]);
            start++;
            cand--;
        }
        cand=candidates;
        while (start<=end && cand) {
            right.push(costs[end]);
            end--;
            cand--;
        }

        for (int i = 0; i < k; i++) {
            int l = left.empty() ? 1e6 : left.top();
            int r = right.empty() ? 1e6 : right.top();
            if (l <= r) {
                ans += l;
                left.pop();
                if (start <= end) {
                    left.push(costs[start]);
                    start++;
                }
            } else {
                ans += r;
                right.pop();
                if (start <= end) {
                    right.push(costs[end]);
                    end--;
                }
            }
        }
        return ans;
    }
};