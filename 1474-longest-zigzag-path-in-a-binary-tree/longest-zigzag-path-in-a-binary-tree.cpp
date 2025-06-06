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
    pair<int,int> dfs(TreeNode* root, int dir){
        if(!root){ return {0,0}; }
        pair<int,int>left=dfs(root->left,0);
        pair<int,int>right=dfs(root->right,1);
        int leftZZ=left.first;
        int rightZZ=right.first;
        if(dir==0){
            rightZZ++;
        }
        if(dir==1){
            leftZZ++;
        }
        int maxSubtreeZZ=max({left.second,right.second,leftZZ,rightZZ});
        int continousZZ= dir ? leftZZ : rightZZ;
        return { continousZZ, maxSubtreeZZ };
    }
    int longestZigZag(TreeNode* root) {
        return dfs(root,-1).second;
    }
};