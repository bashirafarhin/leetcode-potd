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
    int sum(TreeNode* root, int targetSum, vector<int>&path){
        if(!root){ return 0; }
        path.push_back(root->val);
        int ans=sum(root->left, targetSum, path)+sum(root->right, targetSum, path);
        long long sum=targetSum;
        for(int i=path.size()-1;i>=0;i--){
            sum-=path[i];
            if(sum==0){ ans++; }
        }
        path.pop_back();
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        return sum(root, targetSum, path);
    }
};