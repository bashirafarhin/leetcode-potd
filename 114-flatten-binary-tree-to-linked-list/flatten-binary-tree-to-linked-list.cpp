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
    TreeNode* solve(TreeNode* root){
        if(root==NULL || root->left==NULL && root->right==NULL){return root;}
        TreeNode* x=root->right;
        if(root->left !=NULL){
           root->right=solve(root->left);
           TreeNode *curr=root->right;
           while(curr->right !=NULL){curr=curr->right;}
            curr->right=x;
            root->left=NULL;}
        solve(x);
        return root;
    }
public:
    void flatten(TreeNode* root) {
     solve(root);
    }
};