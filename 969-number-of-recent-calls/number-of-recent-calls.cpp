class RecentCounter {
    int n;
    vector<int>counter;
public:
    RecentCounter() {
        n=0;
    }

    int upper_bound(int time){
        int s=0;
        int e=n;
        int ans=0;
        while(s<=e){
            int m=s+(e-s)/2;
            if(counter[m]>=time){
                ans=m;
                e=m-1;
            } else {
                s=m+1;
            }
        }
        return n-ans;
    }
    
    int ping(int t) {
        n++;
        counter.push_back(t);
        return upper_bound(t-3000);
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */