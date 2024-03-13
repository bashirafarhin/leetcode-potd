class Solution {
public:
    int pivotInteger(int n) {
        int totalSum=n*(n+1)/2;
        int low=1;
        int high=n;
        while(low<=high){
            int mid=(low+high)/2;
            int leftSum=mid*(mid+1)/2;
            int rightSum=totalSum-leftSum+mid;
            if(leftSum==rightSum){ return mid; }
            else if(leftSum<rightSum){ low=mid+1; }
            else{ high=mid-1; }
        }
        return -1;
    }
};