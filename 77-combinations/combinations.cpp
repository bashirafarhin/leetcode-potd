class Solution {
    void solve(int i,int k,int n,vector<int>&path,vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(path);
            return;}
        if(i>n){return ;}

        path.push_back(i);
        solve(i+1,k-1,n,path,ans);
        path.pop_back();

        solve(i+1,k,n,path,ans);
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>path;
        solve(1,k,n,path,ans);
        return ans;
    }
};