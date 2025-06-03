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
    void allLevelSum(TreeNode* root, vector<int>&levelSum, int currLevel){
        if(!root){ return; }
        int maxLevelReached=levelSum.size();
        if(currLevel<maxLevelReached){
            levelSum[currLevel]+=root->val;
        } else {
            levelSum.push_back(root->val);
        }
        allLevelSum(root->left, levelSum, currLevel+1);
        allLevelSum(root->right, levelSum, currLevel+1);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int>levelSum;
        allLevelSum(root,levelSum,0);
        int maxSumLevel=0;
        int maxSum=INT_MIN;
        for(int i=0;i<levelSum.size();i++){
            if(maxSum<levelSum[i]){
                maxSum=levelSum[i];
                maxSumLevel=i+1;
            }
        }
        return maxSumLevel;
    }
};