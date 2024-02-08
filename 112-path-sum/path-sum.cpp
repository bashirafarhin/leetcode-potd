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
    int solve(TreeNode* root,int target){
        if(root==NULL){ return false; }
        if(root->left==NULL && root->right==NULL && target-root->val==0){ return true; }
        return solve(root->left,target-root->val) || solve(root->right,target-root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum);
    }
};