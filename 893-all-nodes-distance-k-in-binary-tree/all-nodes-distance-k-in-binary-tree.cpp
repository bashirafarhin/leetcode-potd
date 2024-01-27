/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int countNodes(TreeNode* root){
     if(root==NULL){return 0;}
        return countNodes(root->left)+countNodes(root->right)+1;
    }

    void fillGraph(TreeNode* root,vector<vector<int>>& graph){
     if(root==NULL){return ;}
     if(root->left !=NULL){
         graph[root->val].push_back(root->left->val);
         graph[root->left->val].push_back(root->val);}
     if(root->right !=NULL){
         graph[root->val].push_back(root->right->val);
         graph[root->right->val].push_back(root->val);}
     fillGraph(root->left,graph);
     fillGraph(root->right,graph);
    }

    void dfs(int src,vector<vector<int>>& graph,vector<int>&vis,vector<int>&ans,int dist){
        vis[src]=1;
        if(dist==0){
            ans.push_back(src);
            return;}
        
        for(int neigh : graph[src]){
            if(!vis[neigh]){
                dfs(neigh,graph,vis,ans,dist-1);
            }
        }
        return;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int n=countNodes(root);
        vector<vector<int>> graph(n+1);
        fillGraph(root,graph);
        for(int i=0;i<n;i++){
            cout<<"node "<<i<<" neigh ";
            for(int neigh : graph[i]){cout<<neigh<<" ";}
            cout<<endl;
        }
        vector<int> ans;
        vector<int> vis(n+1,0);
        dfs(target->val,graph,vis,ans,k);
        return ans;
    }
};