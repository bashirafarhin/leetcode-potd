class Solution {
public:
    bool solve(TreeNode* root,long long mini,long long maxi) {
        if (root == NULL) {
            return true;
        }
        if (mini < root->val && root->val < maxi) {
            return solve(root->left, mini, root->val) &&
                   solve(root->right, root->val, maxi);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) { return solve(root,-1e12,1e12); }
};