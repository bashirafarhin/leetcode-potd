class Solution {
public:
    string helper(int n, int k, vector<int>&arr) {
        if(n == 1) { return to_string(arr[1]); }
        int colSize = tgamma(n);
        int col = (k-1) / colSize + 1;
        int rem = (k-1) % colSize + 1;
        char colNum = arr[col]+'0';
        arr.erase(arr.begin()+col);
        string nextPerm = helper(n - 1, rem, arr);
        return colNum+nextPerm;
    }
    string getPermutation(int n, int k) {
        vector<int>arr(n+1,0);
        for(int i=1;i<=n;i++){ arr[i]=i; }
        return helper(n, k, arr);
    }
};