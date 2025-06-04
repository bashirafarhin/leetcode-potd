class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int n = costs.size();
        int left = 0;
        int right = n - 1;
        for (int i = 0; i < candidates; i++) {
            if (left == right) {
                pq.push({costs[left], -1});
            } else if (left < right) {
                pq.push({costs[left], -1});
                pq.push({costs[right], 1});
            }
            left++;
            right--;
            if(left>right){ break; }
        }
        long long cost = 0;
        while (k--) {
            cost += pq.top().first;
            int dir = pq.top().second;
            pq.pop();
            if (left <= right) {
                int ind;
                if (dir == -1) {
                    ind = left;
                    left++;
                } else {
                    ind = right;
                    right--;
                }
                pq.push({costs[ind], dir});
            }
        }
        return cost;
    }
};