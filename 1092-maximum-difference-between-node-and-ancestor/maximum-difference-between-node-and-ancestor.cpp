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
    void solve(TreeNode* root,vector<int>& path,int& ans){
        if(root==NULL){return ;}
        // if(root->left==NULL && root->right==NULL){return root->val;}
        path.push_back(root->val);
        solve(root->left,path,ans);
        solve(root->right,path,ans);
        
        int mini=1e9;
        int maxi=-1e9;
        for(int num : path){
            maxi=max(maxi,num);
            mini=min(mini,num);
        }


        ans=max(ans,maxi-mini);
        path.pop_back();
        return;
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        vector<int> path;
        int ans=0;
        solve(root,path,ans);
        return ans;
    }
};