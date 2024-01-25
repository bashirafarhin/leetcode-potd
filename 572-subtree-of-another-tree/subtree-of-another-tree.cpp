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
    string solve1(TreeNode* root){
      if(root==NULL){return "N";}
      string leftsubtree=solve1(root->left);
      string rightsubtree=solve1(root->right);
      return to_string(root->val)+'L'+leftsubtree+'R'+rightsubtree;;
  }

   string solve2(TreeNode* root,string& subtree,bool& ans){
      if(root==NULL){return "N";}
      string leftsubtree=solve2(root->left,subtree,ans);
      string rightsubtree=solve2(root->right,subtree,ans);
      if(ans==true){return "";}
      string newSubtree=to_string(root->val)+'L'+leftsubtree+'R'+rightsubtree;
      if(newSubtree==subtree){
          ans=true;
      }
      return newSubtree;
  }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
     string subtree=solve1(subRoot);
     bool ans=false;
     solve2(root,subtree,ans);
     return ans;  
    }
};