class Solution {
public:
    void solve(TreeNode* root, int target,vector<int>&path,int&cnt){
        if(root==NULL){ return ; }
        path.push_back(root->val);
        solve(root->left,target,path,cnt);
        solve(root->right,target,path,cnt);
        long sum=0;
        for(int i=path.size()-1;i>=0;i--){
            sum+=(long)path[i];
            if(sum==(long)target){ cnt++; }
        }
        path.pop_back();
        return ;

    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt=0;
        vector<int>path;
        solve(root,targetSum,path,cnt);
        return cnt;
    }
};