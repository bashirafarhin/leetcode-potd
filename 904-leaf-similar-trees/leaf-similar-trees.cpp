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
     void traversetree1(TreeNode* root,vector<int>& leafnode){
         if(root==NULL){return;}
         if(root->left==NULL && root->right==NULL){
             leafnode.push_back(root->val);
             return;}
         traversetree1(root->left,leafnode);
         traversetree1(root->right,leafnode);
         return ;
     }

     bool traversetree2(TreeNode* root,vector<int>& leafnode){
         if(root==NULL){
             return   true ;}
         if(root->left==NULL && root->right==NULL){
             if( !leafnode.empty() && leafnode.back() ==root->val){
                 leafnode.pop_back();
                 return true;}
             return false;
             }

         return traversetree2(root->right,leafnode) && traversetree2(root->left,leafnode);
        
     }


public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
     vector<int> leafnode;
     traversetree1(root1,leafnode);
     if(  !traversetree2(root2,leafnode)){return false;}
     return leafnode.empty()? true: false;


    }
};