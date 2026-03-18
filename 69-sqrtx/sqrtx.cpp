class Solution {
public:
    int mySqrt(int x) {
        int low=0;
        int high=x;
        int ans=0;
        while(low<=high){
            int mid=(high-low)/2+low;
            if((long long)mid*mid<=x){
                ans=mid;
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return ans;
    }
};