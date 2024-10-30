class Solution {
public:
    //multiply 2 matrices
    vector<vector<int>>multiply(vector<vector<int>>&a, vector<vector<int>>&b){
        int n=a.size();
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    ans[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        return ans;
    }

    vector<vector<int>>matrixExponentiate(vector<vector<int>>&a, int n){
        if(n==0){
            return {{1,0},{0,1}}; //identity matrix
        }
        if(n==1){ return a; }
        vector<vector<int>>temp=matrixExponentiate(a,n/2);
        vector<vector<int>>ans=multiply(temp, temp);
        if(n & 1){ ans=multiply(ans,a); }
        return ans;
    }
    int fib(int n) {
        if(n<=1){ return n; }
        vector<vector<int>>A={{1,1},{1,0}};
        vector<vector<int>>ans=matrixExponentiate(A,n-1);
        int s=ans.size();
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans[0][0];
    }
};