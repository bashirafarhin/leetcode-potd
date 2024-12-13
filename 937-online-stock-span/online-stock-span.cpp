class StockSpanner {
    vector<int>arr;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=1;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]>price){ break; }
            ans++;
        }
        arr.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */