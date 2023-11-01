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
    void traverse(TreeNode* root,unordered_map<int,int> &freq){
        if(root==NULL){return ;}
        freq[root->val]++;
        traverse(root->left,freq);
        traverse(root->right,freq);
    }
public:
    //brute force method
    vector<int> findMode(TreeNode* root) {
     unordered_map<int,int> freq;
     traverse(root,freq);
     int maxi=-1e9;
     for(auto it : freq){
         if(maxi<it.second){maxi=it.second;}
     }
     vector<int> ans;
     for(auto it : freq){
         if(maxi==it.second){ans.push_back(it.first);}
     }
     return ans;
    }
};