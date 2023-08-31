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
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(root==NULL){return root;}
         if(root->val==key){
          if(root->left==NULL){return root->right;}
           TreeNode *curr=root->left;
           while(curr->right !=NULL){curr=curr->right;}
           curr->right=root->right;
           return root->left;}
         else if(root->val<key){
          root->right=deleteNode(root->right,key);}
         else{root->left=deleteNode(root->left,key);}
         return root;}
};