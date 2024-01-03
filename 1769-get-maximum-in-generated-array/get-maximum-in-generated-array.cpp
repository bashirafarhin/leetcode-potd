class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1){return n;}
        vector<int> arr(n+1,0);
        arr[0]=0;
        arr[1]=1;
        int maxi=0;
        for(int i=2;i<=n;i++){
            int ind=i/2;
            if(i & 1){
                arr[i]=arr[ind]+arr[ind+1];
            } else {
                arr[i]=arr[ind];
            }
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
};