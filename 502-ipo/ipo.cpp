class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>arr;
        int n=profits.size();
        for(int i=0;i<n;i++){
            arr.push_back({capital[i],profits[i]});
        }
        sort(arr.begin(),arr.end());
        int profit=w;
        priority_queue<int>pq;
        int ind=0;
        for(int i=0;i<k;i++){
            while(ind<n && profit>=arr[ind].first){
                pq.push(arr[ind].second);
                ind++;
            }
            if(pq.size()==0){ break; }
            profit+=pq.top();
            pq.pop();
        }
        return profit;
    }
};