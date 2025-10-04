class Solution {
public:
    bool canSheEatAll(vector<int> piles, int h, int ratePerHour){
        int t=0;
        for(int i=0;i<piles.size();i++){
                t+=ceil((double)piles[i]/ratePerHour);
                if(t>h){
                    return false;
                }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canSheEatAll(piles,h,mid)){
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};