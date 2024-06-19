class Solution {
public:
    int solve(TreeNode* root,int& d){
        if(root==NULL){ return 0; }
        int lh=solve(root->left,d);
        int rh=solve(root->right,d);
        d=max(d,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        solve(root,d);
        return d;
    }
};