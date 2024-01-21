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
    void solve(TreeNode* root,vector<string>& ans,string path){
        if(root==NULL){return ;}

        if(path.length()!=0){
                path+="->";}
        path+=to_string(root->val);

        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
        }

        solve(root->left,ans,path);
        solve(root->right,ans,path);
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root,ans,"");
        return ans;
    }
};