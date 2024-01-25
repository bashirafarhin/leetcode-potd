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
    bool solve(TreeNode* root, TreeNode* subRoot,int start){
        if(root==NULL && subRoot==NULL){return true;}
        if(root==NULL || subRoot==NULL){return false;}
        if(root->val==subRoot->val){
            if( solve(root->left,subRoot->left,1) && solve(root->right,subRoot->right,1))
             {return true;}
        }
        if(start==0){
         return solve(root->left,subRoot,start) || solve(root->right,subRoot,start);
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root,subRoot,0);
    }
};