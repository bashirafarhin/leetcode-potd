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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){ return {0,0}; }
        pair<int,int> l=solve(root->left);
        pair<int,int> r=solve(root->right);

        int lh=l.first , rh=r.first , ld=l.second , rd=r.second;
        
        int currDia=max(lh+rh+1,max(ld,rd));
        return {max(lh,rh)+1,currDia};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).second-1;
    }
};