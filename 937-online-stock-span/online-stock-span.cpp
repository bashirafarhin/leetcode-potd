class StockSpanner {
    int idx;
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        idx=1;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int Index=st.empty() ? 0 : st.top().second;
        st.push({price,idx});
        int ans=idx-Index;
        idx++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */