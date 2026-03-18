class Solution {
public:
    bool calculate(int k, vector<int>& piles, int h){
        int time=0;
        for(int p : piles){
            time += (p/k)+((p%k)>= 1? 1 : 0);
            if(time>h){ return false; }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(), piles.end());
        int ans=h;
        while(low<=high){
            int mid=(high-low)/2+low;
            if(calculate(mid,piles, h)){
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};