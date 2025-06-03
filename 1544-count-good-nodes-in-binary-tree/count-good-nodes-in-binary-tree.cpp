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
    int gn(TreeNode* root, int limit){
        if(!root){ return 0; }
        int ans=0;
        if(root->val >= limit){
            ans++;
        }
        limit=max(limit,root->val);
        return ans+gn(root->left,limit)+gn(root->right,limit);
    }
    int goodNodes(TreeNode* root) {
        return gn(root,INT_MIN);
    }
};