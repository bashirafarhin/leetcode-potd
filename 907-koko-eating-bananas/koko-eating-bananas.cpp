class Solution {
public:
    bool checkIfFinish(int k, vector<int>& piles, int h){
        int hoursTake=0;
        for(int i=0;i<piles.size();i++){
            hoursTake+=ceil((double)piles[i]/k);
            if(hoursTake>h){ return false; }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=(high+(low-high)/2);
            if(checkIfFinish(mid,piles,h)){
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};