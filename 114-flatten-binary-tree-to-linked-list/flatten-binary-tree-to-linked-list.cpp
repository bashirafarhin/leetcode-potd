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
    void in_order(TreeNode* root,vector<TreeNode*> &inorder){
        if(root==NULL){return;}
        inorder.push_back(root);
        in_order(root->left,inorder);
        in_order(root->right,inorder);
    }
public:
    //brute force solution
    void flatten(TreeNode* root) {
     vector<TreeNode*> inorder;
     in_order(root,inorder);
     int n=inorder.size();
     for(int i=0;i<n-1;i++){
         inorder[i]->left=NULL;
         inorder[i]->right=inorder[i+1];
     }
    }
};