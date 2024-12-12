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
    int helper(TreeNode* root, int node){
        if(root==NULL){
            return 0;
        }
        int ans=0;
        if(root->val>=node){
            return 1+helper(root->left, root->val)+helper(root->right, root->val);
        }
        return helper(root->left, node)+helper(root->right, node);
    }
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
};