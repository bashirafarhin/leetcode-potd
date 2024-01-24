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
    int check(vector<int>&freq){
        bool odd=true;
        for(int i=1;i<=9;i++){
            if(freq[i]==0){continue;}
            if(freq[i] & 1){
                if(odd){odd=false;}
                else{return 0;}
            }
        }
        return 1;
    }

    int  solve(TreeNode* root,vector<int>&freq){
        if(root==NULL){return 0;}

        if(root->left==NULL && root->right==NULL){
           freq[root->val]++;
           int ans=check(freq);
           freq[root->val]--;
           return ans;
        }

        freq[root->val]++;
        int l=solve(root->left,freq);
        int r=solve(root->right,freq);
        freq[root->val]--;
        return l+r;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
     vector<int>freq(10,0);
     return solve(root,freq);

    }
};