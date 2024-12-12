class Solution {
public:
    TreeNode* helper(TreeNode* root, int val){
        if(root==NULL){
            return 0;
        }
        if(root->val==val){
            return root;
        } else if(root->val>val){
            return helper(root->left,val);
        } else {
            return helper(root->right,val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return helper(root, val);
    }
};