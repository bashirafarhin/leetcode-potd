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
        if(!root){ return root; }
        if(root->val==key){
            TreeNode* curr=root->right;
            if(!curr){ return root->left; }
            while(curr->left){
            curr=curr->left;
            }
            curr->left=root->left;
            return root->right;
        }
        root->left=deleteNode(root->left, key);
        root->right=deleteNode(root->right, key);
        return root;
    }
};