/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int& ans,int& lvl,int currlvl){
        if(root==NULL){ return ; }
        if(lvl<=currlvl){
            ans=root->val;
            lvl=currlvl;
        }
        solve(root->right,ans,lvl,currlvl+1);
        solve(root->left,ans,lvl,currlvl+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans=0,lvl=0;
        solve(root,ans,lvl,0);
        return ans;
    }
};