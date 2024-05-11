class Solution {
public:
    void solve(TreeNode* root,int& ans,vector<int>&path){
        if(root==NULL){ return ; }
        path.push_back(root->val);
        solve(root->left,ans,path);
        solve(root->right,ans,path);
        int mini=1e9;
        int maxi=-1e9;
        for(int node : path){
            mini=min(node,mini);
            maxi=max(node,maxi);
        }
        ans=max(ans,maxi-mini);
        path.pop_back();
        return;
    }

    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        vector<int>path;
        solve(root,ans,path);
        return ans;
    }
};