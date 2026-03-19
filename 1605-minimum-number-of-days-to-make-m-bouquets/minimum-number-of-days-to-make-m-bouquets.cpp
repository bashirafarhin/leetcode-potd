class Solution {
public:
// is it possible to make m bouquets after d days
    bool isPossibleToMake(vector<int>& bloomDay, int m, int k, int d){
        int n=bloomDay.size();
        int numOfBouquetPossible=0;
        int window_start=0;
        for(int i=0;i<n;i++){
            int window_end=i;
            if(bloomDay[i]-d>0){
                window_start=i+1;
            }
            else if(window_end-window_start+1==k){
                numOfBouquetPossible++;
                window_start=i+1;
            }
        }
        return numOfBouquetPossible>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long)m*k>n){
            return -1;
        }
        int ans=-1;
        int low=0;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=(high-low)/2 + low;
            if(isPossibleToMake(bloomDay,m,k,mid)){
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};