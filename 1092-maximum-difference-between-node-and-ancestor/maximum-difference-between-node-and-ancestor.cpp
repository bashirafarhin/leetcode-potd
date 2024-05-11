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
    void solve2(TreeNode* root,int data,int& curr){
        if(root==NULL){ return ; }
        curr=max(curr,abs(data-root->val));
        solve2(root->left,data,curr);
        solve2(root->right,data,curr);

    }

    void solve(TreeNode* root,int& ans){
        if(root==NULL){ return ; }
        int curr=0;
        solve2(root,root->val,curr);
        ans=max(ans,curr);
        solve(root->left,ans);
        solve(root->right,ans);
    }

    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};