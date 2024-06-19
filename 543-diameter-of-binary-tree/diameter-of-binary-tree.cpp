class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){ return 0; }
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }

    int solve(TreeNode* root){
        if(root==NULL){ return 0; }
        int lh=height(root->left);
        int rh=height(root->right);
        int ld=solve(root->left);
        int rd=solve(root->right);
        int d=max( lh+rh,max(ld,rd));
        return d;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root);
    }
};