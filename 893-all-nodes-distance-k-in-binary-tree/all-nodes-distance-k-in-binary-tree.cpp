
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

    vector<int> bfs(int src,vector<vector<int>>& graph,int k){
        queue<pair<int,int>> q; //{node,distance}
        vector<int>vis(graph.size()+1,0);
        vector<int> ans;
        q.push({src,0});
        while(!q.empty()){
            int size=q.size();
            while(size--){
               int node=q.front().first;
               int dist=q.front().second;
               q.pop();
               vis[node]=1;
               if(dist==k){
                   ans.push_back(node);
                   continue;}
               for(int neigh : graph[node]){
                   if(!vis[neigh]){ q.push({neigh,dist+1});}
               }
            }
        }
        return ans;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int n=countNodes(root);
        vector<vector<int>> graph(n+1);
        fillGraph(root,graph);       
        return bfs(target->val,graph,k);
    }
};