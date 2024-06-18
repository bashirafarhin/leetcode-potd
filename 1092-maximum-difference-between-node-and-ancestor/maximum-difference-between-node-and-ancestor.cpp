class Solution {
public:
    int ans=0;
    int solve(TreeNode* root,int mini,int maxi){
        if(root==NULL){ return maxi-mini; }
        mini=min(root->val,mini);
        maxi=max(root->val,maxi);
        int l=solve(root->left,mini,maxi);
        int r=solve(root->right,mini,maxi);
        ans=max(ans,max(l,r));
        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root,1e9,-1e9);
        return ans;
    }
};