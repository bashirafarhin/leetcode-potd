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
    void rightView(TreeNode* root, int level, vector<int>&view){
        if(!root){ return; }
        int currLevel=view.size();
        if(level>=currLevel){
            view.push_back(root->val);
        }
        rightView(root->right, level+1, view);
        rightView(root->left, level+1, view);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>view;
        rightView(root, 0, view);
        return view;
    }
};