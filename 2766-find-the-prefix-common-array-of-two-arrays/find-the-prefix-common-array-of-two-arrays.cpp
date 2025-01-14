class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>store1(n+1,0);
        vector<int>store2(n+1,0);
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            store1[A[i]]=1;
            store2[B[i]]=1;
            if(store1[B[i]]){
                ans[i]++;
            }
            if(A[i] !=B[i] && store2[A[i]]){
                ans[i]++;
            }
            if(i){
                ans[i]+=ans[i-1];
            }
        }
        return ans;
    }
};