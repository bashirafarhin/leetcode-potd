class Solution {
public:
    int helper(TreeNode* root, int&moves){
        if(root==NULL){
            return 0;
        }
        int l=helper(root->left, moves);
        int r=helper(root->right, moves);
        int extras=root->val+l+r-1;
        moves+=abs(extras);
        return extras;
    }
    int distributeCoins(TreeNode* root) {
        int moves=0;
        helper(root, moves);
        return moves;
    }
};