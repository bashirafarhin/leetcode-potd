class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root==NULL){ return true; }
        if(!root->left && !root->right){
            return root->val==1;
        }
        bool left=evaluateTree(root->left);
        bool right=evaluateTree(root->right);

        if(left && right){
            return true; }
        if( (left || right) && root->val==2){
            return true;
        }
        return false;

    }
};