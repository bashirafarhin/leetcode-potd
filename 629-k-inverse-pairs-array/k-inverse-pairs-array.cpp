class Solution {
    int mod=1e9+7;
public:
    int kInversePairs(int N, int K) {
        vector<int>curr(K+1,0);
        vector<int>prev(K+1,0);
        for(int n=1;n<=N;n++){
            for(int k=0;k<=K;k++){
                if(k==0){ curr[k]=1; }
                else {
                 int count=0;
                 for(int i=0;i<=min(k,n-1);i++){
                  count=( count + prev[k-i] )% mod; }
                 curr[k]=count;
                }
            }
            prev=curr;
        }
        return curr[K];
    }
};