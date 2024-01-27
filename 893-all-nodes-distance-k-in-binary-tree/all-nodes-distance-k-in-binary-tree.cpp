
class Solution {
    void parentPointers(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root==NULL){return;}
        if(root->left != NULL){ parent[root->left]=root; }
        if(root->right != NULL){ parent[root->right]=root; }
        parentPointers(root->left,parent);
        parentPointers(root->right,parent);
    }

    vector<int> bfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent,int k){
        queue<TreeNode*> q;
        unordered_set<TreeNode*>vis; //to store visited node
        q.push(root);
        int level=0;
        vis.insert(root);
        while(!q.empty()){
            int size=q.size();
            if(level == k){ break;}
            level++;
            while(size--){
               TreeNode* node=q.front();
               q.pop();
               if(node->left && vis.find(node->left)==vis.end()){
                      q.push(node->left);
                      vis.insert(node->left);}
               if(node->right && vis.find(node->right)==vis.end()){
                   q.push(node->right);
                   vis.insert(node->right);}
               if(parent[node] && vis.find(parent[node])==vis.end()){
                   q.push(parent[node]); 
                   vis.insert(parent[node]);}           
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();}
        return ans;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent ; //map to store parent pointers
        parentPointers(root,parent);
        return bfs(target,parent,k);
    }
};