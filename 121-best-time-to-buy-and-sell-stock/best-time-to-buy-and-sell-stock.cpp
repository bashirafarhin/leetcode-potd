class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int p=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            p=max(p, prices[i]-buy);
            buy=min(buy, prices[i]);
        }
        return p;
    }
};