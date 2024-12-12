class RecentCounter {
    vector<int>req;
public:
    RecentCounter() {
        req={};
    }
    
    int ping(int t) {
        req.push_back(t);
        int cnt=0;
        for(int i=req.size()-1;i>=0;i--){
            if(t-3000>req[i]){ break; }
            cnt++;
        }
        return cnt;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */