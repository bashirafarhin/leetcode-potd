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
    int stringToNum(string num){
        string var=num;
        int ans=stoi(var);
        return ans;
    }

    int solve(TreeNode* root,string num){
        if(root==NULL){ return 0; }
        char ch=root->val+48;

        if(root->left==NULL && root->right==NULL) {
            return stringToNum(num+ch); }
        
        return solve(root->left,num+ch)+solve(root->right,num+ch);
        
    }
    int sumNumbers(TreeNode* root) {
        return solve(root,"");
    }
};