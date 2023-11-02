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
    //subtree_val,number_of_nodes
    pair<int,int> func(TreeNode* root,int &ans){
        if(root==NULL){return {0,0};}
        pair<int,int> l=func(root->left,ans);
        pair<int,int> r=func(root->right,ans);
        pair<int,int> s={l.first+r.first+root->val,l.second+r.second+1};
        int subtree_avg_val=s.first/s.second;
        if(root->val==subtree_avg_val){ans++;}
        return s;

    }
public:
    int averageOfSubtree(TreeNode* root) {
     int ans=0;
     func(root,ans);
     return ans;
    }
};