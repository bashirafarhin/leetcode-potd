class Solution {
    void solve(int i,int k,int target,vector<int>&path,vector<vector<int>>&ans){
        if(target==0 && k==0){
            ans.push_back(path);
            return;}
        if(k==0 || i==10){return ;}
        for(int j=i;j<=9;j++){
            path.push_back(j);
            solve(j+1,k-1,target-j,path,ans);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>path;
        solve(1,k,n,path,ans);
        return ans;
    }
};